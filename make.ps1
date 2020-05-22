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
rm .\lib\*.*

.\FASM.EXE .\src\libfastact.asm .\lib\libfastact.dll

cp .\src\graphics\x64\Release\LIBFASTACTGRAPHICS.dll .\lib
cp .\src\graphics\x64\Release\LIBFASTACTGRAPHICS.lib .\lib
cp .\src\graphics\libfastact_graphics\libfastact_graphics.h .\include\libfastact_graphics.h

cp .\src\cas\x64\Release\LIBFASTACTCAS.dll .\lib
cp .\src\cas\x64\Release\LIBFASTACTCAS.lib .\lib
cp .\src\cas\libfastact_cas\libfastact_cas.h .\include\libfastact_cas.h

[string]$modulePath = ".\lib\libfastact.dll"
[string]$machine = "x64"

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