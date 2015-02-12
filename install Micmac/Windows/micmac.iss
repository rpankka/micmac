; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "MicMac64bits"
#define MyAppVersion "1.0 rev 3811"
#define MyAppPublisher "I.G.N."
#define MyAppURL "http://www.ign.fr/"
#define MyAppExeName "bin\mm3d.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{15775992-7521-43B0-96F3-713223312D5F}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName=c:\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes
ChangesEnvironment=yes
ArchitecturesInstallIn64BitMode=x64
WizardSmallImageFile="..\images\IGN_logo_2012.bmp"
WizardImageFile="..\images\ban_IGN_logo_2012.bmp"
LicenseFile="..\Licence_CeCILL_V2.1-fr.txt"

[Languages]
Name: "french"; MessagesFile: "compiler:Languages\French.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "..\..\LISEZMOI"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\README"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\bin\*.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "..\..\bin\*.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "..\..\bin\platforms\qwindows.dll"; DestDir: "{app}\bin\platforms"; Flags: ignoreversion
Source: "..\..\bin\imageformats\qgif.dll"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion
Source: "..\..\bin\imageformats\qico.dll"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion
Source: "..\..\bin\imageformats\qjpeg.dll"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion
Source: "..\..\bin\imageformats\qmng.dll"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion
Source: "..\..\bin\imageformats\qsvg.dll"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion
Source: "..\..\bin\imageformats\qtga.dll"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion
Source: "..\..\bin\imageformats\qtiff.dll"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion
Source: "..\..\bin\imageformats\qwbmp.dll"; DestDir: "{app}\bin\imageformats"; Flags: ignoreversion
Source: "..\..\binaire-aux\*.exe"; DestDir: "{app}\binaire-aux"; Flags: ignoreversion
Source: "..\..\binaire-aux\*.dll"; DestDir: "{app}\binaire-aux"; Flags: ignoreversion
Source: "..\..\data\*"; DestDir: "{app}\data"; Flags: ignoreversion
Source: "..\..\data\Tabul\*"; DestDir: "{app}\data\Tabul"; Flags: ignoreversion
Source: "..\..\include\XML_MicMac\*"; DestDir: "{app}\include\XML_MicMac"; Flags: ignoreversion
Source: "..\..\include\XML_GEN\*"; DestDir: "{app}\include\XML_GEN"; Flags: ignoreversion
Source: "..\..\include\qt\*"; DestDir: "{app}\include\qt"; Flags: ignoreversion
Source: "..\..\include\qt\translations\*"; DestDir: "{app}\include\qt\translations"; Flags: ignoreversion

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\Saisie"; Filename: "{app}\bin\SaisieQT.exe"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[CustomMessages]
AppAddPath=Ajout du dossier dans la variable d'environement Path (requis)

[Registry]
Root: HKLM; Subkey: "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"; ValueType: expandsz; ValueName: "Path"; ValueData: "{olddata};{app}\bin"

[Tasks]
Name: modifypath; Description:{cm:AppAddPath};   

[Code]
const
    ModPathName = 'modifypath';
    ModPathType = 'system';

function ModPathDir(): TArrayOfString;
begin
    setArrayLength(Result, 1)
    Result[0] := ExpandConstant('{app}\bin');
end;

function IsDotNetDetected(version: string; service: cardinal): boolean;
// Indicates whether the specified version and service pack of the .NET Framework is installed.
//
// version -- Specify one of these strings for the required .NET Framework version:
//    'v1.1.4322'     .NET Framework 1.1
//    'v2.0.50727'    .NET Framework 2.0
//    'v3.0'          .NET Framework 3.0
//    'v3.5'          .NET Framework 3.5
//    'v4\Client'     .NET Framework 4.0 Client Profile
//    'v4\Full'       .NET Framework 4.0 Full Installation
//    'v4.5'          .NET Framework 4.5
//
// service -- Specify any non-negative integer for the required service pack level:
//    0               No service packs required
//    1, 2, etc.      Service pack 1, 2, etc. required
var
    key: string;
    install, release, serviceCount: cardinal;
    check45, success: boolean;
begin
    // .NET 4.5 installs as update to .NET 4.0 Full
    if version = 'v4.5' then begin
        version := 'v4\Full';
        check45 := true;
    end else
        check45 := false;

    // installation key group for all .NET versions
    key := 'SOFTWARE\Microsoft\NET Framework Setup\NDP\' + version;

    // .NET 3.0 uses value InstallSuccess in subkey Setup
    if Pos('v3.0', version) = 1 then begin
        success := RegQueryDWordValue(HKLM, key + '\Setup', 'InstallSuccess', install);
    end else begin
        success := RegQueryDWordValue(HKLM, key, 'Install', install);
    end;

    // .NET 4.0/4.5 uses value Servicing instead of SP
    if Pos('v4', version) = 1 then begin
        success := success and RegQueryDWordValue(HKLM, key, 'Servicing', serviceCount);
    end else begin
        success := success and RegQueryDWordValue(HKLM, key, 'SP', serviceCount);
    end;

    // .NET 4.5 uses additional value Release
    if check45 then begin
        success := success and RegQueryDWordValue(HKLM, key, 'Release', release);
        success := success and (release >= 378389);
    end;

    result := success and (install = 1) and (serviceCount >= service);
end;


function InitializeSetup(): Boolean;
begin
    if not IsDotNetDetected('v2.0.50727', 0) then begin
        MsgBox('MicMac n�cessite Microsoft .NET Framework 2.0 Client.'#13#13
            'Installer cette application,'#13
            'et relancer le setup de MicMac.', mbInformation, MB_OK);
        result := false;
    end else
        result := true;
end;

[Files]
Source: ".\redis\VC_2010_SP1_REDIST_X64\vcredist_x64.exe"; DestDir: {tmp}\VC_2010_SP1_REDIST_X64; Flags: deleteafterinstall
Source: ".\redis\VC_2008_REDIST_X86\vcredist_x86.exe"; DestDir: {tmp}\VC_2008_REDIST_X86; Flags: deleteafterinstall

[Run]
; add the Parameters, WorkingDir and StatusMsg as you wish, just keep here
; the conditional installation Check
Filename: "{tmp}\VC_2010_SP1_REDIST_X64\vcredist_x64.exe"; Check: VCRedistNeedsInstall_VC_2010_REDIST_X64
Filename: "{tmp}\VC_2008_REDIST_X86\vcredist_x86.exe"; Check: VCRedistNeedsInstall_VC_2008_REDIST_X86                                                                                      

[Code]
#IFDEF UNICODE
  #DEFINE AW "W"
#ELSE
  #DEFINE AW "A"
#ENDIF
type
  INSTALLSTATE = Longint;
const
  INSTALLSTATE_INVALIDARG = -2;  // An invalid parameter was passed to the function.
  INSTALLSTATE_UNKNOWN = -1;     // The product is neither advertised or installed.
  INSTALLSTATE_ADVERTISED = 1;   // The product is advertised but not installed.
  INSTALLSTATE_ABSENT = 2;       // The product is installed for a different user.
  INSTALLSTATE_DEFAULT = 5;      // The product is installed for the current user.

  VC_2005_REDIST_X86 = '{A49F249F-0C91-497F-86DF-B2585E8E76B7}';
  VC_2005_REDIST_X64 = '{6E8E85E8-CE4B-4FF5-91F7-04999C9FAE6A}';
  VC_2005_REDIST_IA64 = '{03ED71EA-F531-4927-AABD-1C31BCE8E187}';
  VC_2005_SP1_REDIST_X86 = '{7299052B-02A4-4627-81F2-1818DA5D550D}';
  VC_2005_SP1_REDIST_X64 = '{071C9B48-7C32-4621-A0AC-3F809523288F}';
  VC_2005_SP1_REDIST_IA64 = '{0F8FB34E-675E-42ED-850B-29D98C2ECE08}';
  VC_2005_SP1_ATL_SEC_UPD_REDIST_X86 = '{837B34E3-7C30-493C-8F6A-2B0F04E2912C}';
  VC_2005_SP1_ATL_SEC_UPD_REDIST_X64 = '{6CE5BAE9-D3CA-4B99-891A-1DC6C118A5FC}';
  VC_2005_SP1_ATL_SEC_UPD_REDIST_IA64 = '{85025851-A784-46D8-950D-05CB3CA43A13}';

  VC_2008_REDIST_X86 = '{FF66E9F6-83E7-3A3E-AF14-8DE9A809A6A4}';
  VC_2008_REDIST_X64 = '{350AA351-21FA-3270-8B7A-835434E766AD}';
  VC_2008_REDIST_IA64 = '{2B547B43-DB50-3139-9EBE-37D419E0F5FA}';
  VC_2008_SP1_REDIST_X86 = '{9A25302D-30C0-39D9-BD6F-21E6EC160475}';
  VC_2008_SP1_REDIST_X64 = '{8220EEFE-38CD-377E-8595-13398D740ACE}';
  VC_2008_SP1_REDIST_IA64 = '{5827ECE1-AEB0-328E-B813-6FC68622C1F9}';
  VC_2008_SP1_ATL_SEC_UPD_REDIST_X86 = '{1F1C2DFC-2D24-3E06-BCB8-725134ADF989}';
  VC_2008_SP1_ATL_SEC_UPD_REDIST_X64 = '{4B6C7001-C7D6-3710-913E-5BC23FCE91E6}';
  VC_2008_SP1_ATL_SEC_UPD_REDIST_IA64 = '{977AD349-C2A8-39DD-9273-285C08987C7B}';
  VC_2008_SP1_MFC_SEC_UPD_REDIST_X86 = '{9BE518E6-ECC6-35A9-88E4-87755C07200F}';
  VC_2008_SP1_MFC_SEC_UPD_REDIST_X64 = '{5FCE6D76-F5DC-37AB-B2B8-22AB8CEDB1D4}';
  VC_2008_SP1_MFC_SEC_UPD_REDIST_IA64 = '{515643D1-4E9E-342F-A75A-D1F16448DC04}';

  VC_2010_REDIST_X86 = '{196BB40D-1578-3D01-B289-BEFC77A11A1E}';
  VC_2010_REDIST_X64 = '{DA5E371C-6333-3D8A-93A4-6FD5B20BCC6E}';
  VC_2010_REDIST_IA64 = '{C1A35166-4301-38E9-BA67-02823AD72A1B}';
  VC_2010_SP1_REDIST_X86 = '{F0C3E5D1-1ADE-321E-8167-68EF0DE699A5}';
  VC_2010_SP1_REDIST_X64 = '{1D8E6291-B0D5-35EC-8441-6616F567A0F7}';
  VC_2010_SP1_REDIST_IA64 = '{88C73C1C-2DE5-3B01-AFB8-B46EF4AB41CD}';

function MsiQueryProductState(szProduct: string): INSTALLSTATE; 
  external 'MsiQueryProductState{#AW}@msi.dll stdcall';

function VCVersionInstalled(const ProductID: string): Boolean;
begin
  Result := MsiQueryProductState(ProductID) = INSTALLSTATE_DEFAULT;
end;

function VCRedistNeedsInstall_VC_2010_REDIST_X64: Boolean;
begin
  // here the Result must be True when you need to install your VCRedist
  // or False when you don't need to, so now it's upon you how you build
  // this statement, the following won't install your VC redist only when
  // the Visual C++ 2010 Redist (x86) and Visual C++ 2010 SP1 Redist(x86)
  // are installed for the current user
  Result := not (VCVersionInstalled(VC_2010_SP1_REDIST_X64) or VCVersionInstalled(VC_2010_REDIST_X64)) ;
end;

function VCRedistNeedsInstall_VC_2008_REDIST_X86: Boolean;
begin
  Result := not (VCVersionInstalled(VC_2008_REDIST_X86) or VCVersionInstalled(VC_2008_SP1_REDIST_X86)) ;
end;
#include "modpath.iss"