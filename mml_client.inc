{
	This file is part of the Mufasa Macro Library (MML)
	Copyright (c) 2009-2012 by Raymond van Venetië and Merlijn Wajer

    MML is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libMML is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libMML.  If not, see <http://www.gnu.org/licenses/>.

	See the file COPYING, included in this distribution,
	for details about the copyright.

    Client wrappers for libMML.
}

{%MainUnit mml.lpr}

function Client_Create(plugin_dir: shortstring; IOManager: Pointer): Pointer; cdecl;
begin
  Result := TClient.Create(plugin_dir, TIOManager(IOManager));
end;

procedure Client_Free(Client: Pointer); cdecl;
begin
  TClient(Client).Free;
end;

function Client_getIOManager(Client: Pointer): Pointer; cdecl;
begin
  Result := TClient(Client).IOManager;
end;

function Client_getMFiles(Client: Pointer): Pointer; cdecl;
begin
  Result := TClient(Client).MFiles;
end;

function Client_getMFinder(Client: Pointer): Pointer; cdecl;
begin
  Result := TClient(Client).MFinder;
end;

function Client_getMBitmaps(Client: Pointer): Pointer; cdecl;
begin
  Result := TClient(Client).MBitmaps;
end;

function Client_getMDTMs(Client: Pointer): Pointer; cdecl;
begin
  Result := TClient(Client).MDTMs;
end;

function Client_getMOCR(Client: Pointer): Pointer; cdecl;
begin
  Result := TClient(Client).MOCR;
end;

procedure Client_setWriteLnProc(Client: Pointer; WriteLnProc: Pointer); cdecl;
begin
  TClient(Client).WritelnProc := TWriteLnProc(WriteLnProc);
end;

procedure Client_WriteLn(Client: Pointer; s: shortstring); cdecl;
begin
  TClient(Client).WriteLn(s);
end;

exports
  Client_Create,
  Client_Free,
  Client_getIOManager,
  Client_getMFiles,
  Client_getMFinder,
  Client_getMBitmaps,
  Client_getMDTMs,
  Client_getMOCR,
  Client_setWriteLnProc,
  Client_WriteLn;
