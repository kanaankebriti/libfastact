#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
#░This file is part of libfastasm.										░
#░																		░
#░libfastasm is free software: you can redistribute it and/or modify	░
#░it under the terms of the GNU General Public License as published by	░
#░the Free Software Foundation, either version 3 of the License, or		░
#░(at your option) any later version.									░
#░																		░
#░libfastasm is distributed in the hope that it will be useful,			░
#░but WITHOUT ANY WARRANTY; without even the implied warranty of		░
#░MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the			░
#░GNU General Public License for more details.							░
#░																		░
#░You should have received a copy of the GNU General Public License		░
#░along with Foobar.  If not, see <https://www.gnu.org/licenses/>.		░
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
[string]$machine = Read-Host -Prompt "build target (x86 or x64)"

# check for input
if ($machine -eq "x64")
{
	[string]$modulePath = ".\lib\LIBFASTACTCORE_" + $machine + ".dll"
	.\FASM.EXE .\src\core\libfastactcore_x64.asm .\lib\LIBFASTACTCORE_x64.dll
}
elseif($machine -eq "x86")
{
	[string]$modulePath = ".\lib\LIBFASTACTCORE_" + $machine + ".dll"
	.\FASM.EXE .\src\core\libfastactcore_x86.asm .\lib\LIBFASTACTCORE_x86.dll
}
else
{
	Write-Host "WRONG Architecture"
	return
}

cp .\src\graphics\x64\Release\LIBFASTACTGRAPHICS_x64.dll .\lib\LIBFASTACTGRAPHICS_x64.dll
cp .\src\graphics\x64\Release\LIBFASTACTGRAPHICS_x64.lib .\lib\LIBFASTACTGRAPHICS_x64.lib
cp .\src\graphics\x86\Release\LIBFASTACTGRAPHICS_x86.dll .\lib\LIBFASTACTGRAPHICS_x86.dll
cp .\src\graphics\x86\Release\LIBFASTACTGRAPHICS_x86.lib .\lib\LIBFASTACTGRAPHICS_x86.lib
cp .\src\graphics\libfastact_graphics\libfastact_graphics.h .\include\libfastact_graphics.h

cp .\src\cas\x64\Release\LIBFASTACTCAS_x64.dll .\lib\LIBFASTACTCAS_x64.dll
cp .\src\cas\x64\Release\LIBFASTACTCAS_x64.lib .\lib\LIBFASTACTCAS_x64.lib
cp .\src\cas\x86\Release\LIBFASTACTCAS_x86.dll .\lib\LIBFASTACTCAS_x86.dll
cp .\src\cas\x86\Release\LIBFASTACTCAS_x86.lib .\lib\LIBFASTACTCAS_x86.lib
cp .\src\cas\libfastact_cas\libfastact_cas.h .\include\libfastact_cas.h

if(!(Test-Path $modulePath -PathType Leaf))
{
	Write-Warning "$modulePath is an invalid module path"
	return
}

$exports = (dumpbin /nologo /exports $modulePath) | Out-String
$tabStart = $exports.IndexOf("ordinal hint")
$exportsTab = $exports.Substring($tabStart) -split "\s+"

$numImports = 0
$def = @("EXPORTS")
for($i = 4; $exportsTab[$i] -ne "Summary"; $i += 4)
{
	$def += $exportsTab[$i + 3]
	$numImports++
}

$moduleFileInfo = New-Object System.IO.FileInfo($modulePath)

$defFileName = ".\lib\" + $moduleFileInfo.BaseName + ".def"
($def -join "`r`n") | Out-File $defFileName

$libMachine = if($machine) {" /machine:$machine"} else {""}
$libFileName = ".\lib\" + $moduleFileInfo.BaseName + ".lib"
Invoke-Expression ("lib /nologo /def:$defFileName /out:$libFileName" + $libMachine)

if(Test-Path $libFileName -PathType Leaf)
{
	Write-Host "`r`nCreated $libFileName importing $numImports exports`r`n"
	Write-Host "#pragma comment(lib, `"$libFileName`")"
}
else
{
	Write-Warning "$libFileName was unable to be created"
}