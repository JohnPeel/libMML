program project1;

uses interfaces;

{$linklib mml}

function Client_Create(plugin_dir: shortstring; IOManager: Pointer): Pointer; external 'mml.so cdecl';
function Client_Free(Client: Pointer): Pointer; external 'mml.so cdecl';
function Client_getMFinder(Client: Pointer): Pointer; external 'mml.so cdecl';
function Client_getIOManager(Client: Pointer): Pointer; external 'mml.so cdecl';

procedure IOManager_SetDesktop(IOManager: Pointer); external 'mml.so cdecl';

function Finder_CountColor(Finder: Pointer; Color, xs, ys, xe, ye: Integer): Integer; external 'mml.so cdecl';

var
  Client: Pointer;

begin
  Client := Client_Create('/home/john/src/libmml/plugins', nil);
  IOManager_SetDesktop(Client_getIOManager(Client));
  WriteLn(Finder_CountColor(Client_getMFinder(Client), 4012083, 0, 0, 500, 500));
  Client_Free(Client);
end.
