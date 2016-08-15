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

    Files wrappers for libMML.
}

{%MainUnit mml.lpr}

function Files_Create(Client: Pointer): Pointer; cdecl;
begin
  Result := TMFiles.Create(TClient(Client));
end;

procedure Files_Free(Files: Pointer); cdecl;
begin
  TMFiles(Files).Free;
end;

{OpenFileEvent: TOpenFileEvent;    //TODO: Should these events be cdecl?
WriteFileEvent: TWriteFileEvent;}

function Files_CreateFile(Files: Pointer; Path: shortstring): Integer; cdecl;
begin
  Result := TMFiles(Files).CreateFile(Path);
end;

function Files_OpenFile(Files: Pointer; Path: shortstring; Shared: Boolean): Integer; cdecl;
begin
  Result := TMFiles(Files).OpenFile(Path, Shared);
end;

function Files_RewriteFile(Files: Pointer; Path: shortstring; Shared: Boolean): Integer; cdecl;
begin
  Result := TMFiles(Files).RewriteFile(Path, Shared);
end;

function Files_AppendFile(Files: Pointer; Path: shortstring): Integer; cdecl;
begin
  Result := TMFiles(Files).AppendFile(Path);
end;

function Files_DeleteFile(Files: Pointer; Filename: shortstring): Boolean; cdecl;
begin
  Result := TMFiles(Files).DeleteFile(Filename);
end;

function Files_RenameFile(Files: Pointer; OldName, NewName: shortstring): Boolean; cdecl;
begin
  Result := TMFiles(Files).RenameFile(OldName, NewName);
end;

procedure Files_CloseFile(Files: Pointer; FileNum: Integer); cdecl;
begin
  TMFiles(Files).CloseFile(FileNum);
end;

procedure Files_WriteINI(Files: Pointer; const Section, KeyName, NewString : shortstring; FileName: shortstring); cdecl;
begin
  TMFiles(Files).WriteINI(Section, KeyName, NewString, FileName);
end;

function Files_ReadINI(Files: Pointer; const Section, KeyName: shortstring; FileName: shortstring): shortstring; cdecl;
begin
  Result := TMFiles(Files).ReadINI(Section, KeyName, FileName);
end;

procedure Files_DeleteINI(Files: Pointer; const Section, KeyName : shortstring; FileName : shortstring); cdecl;
begin
  TMFiles(Files).DeleteINI(Section, KeyName, FileName);
end;

function Files_EndOfFile(Files: Pointer; FileNum: Integer): Boolean; cdecl;
begin
  Result := TMFiles(Files).EndOfFile(FileNum);
end;

function Files_FileSize(Files: Pointer; FileNum: Integer): LongInt; cdecl;
begin
  Result := TMFiles(Files).FileSizeMuf(FileNum);
end;

function Files_ReadFileString(Files: Pointer; FileNum: Integer; out s: shortstring; x: Integer): Boolean; cdecl;
var
  str: string;
begin
  str := '';
  Result := TMFiles(Files).ReadFileString(FileNum, str, x);
  s := str;
end;

function Files_WriteFileString(Files: Pointer; FileNum: Integer; const s: shortstring): Boolean; cdecl;
begin
  Result := TMFiles(Files).WriteFileString(FileNum, s);
end;

function Files_SetFileCharPointer(Files: Pointer; FileNum, cChars, Origin: Integer): Integer; cdecl;
begin
  Result := TMFiles(Files).SetFileCharPointer(FileNum, cChars, Origin);
end;

function Files_FilePointerPos(Files: Pointer; FileNum: Integer): Integer; cdecl;
begin
  Result := TMFiles(Files).FilePointerPos(FileNum);
end;

exports
  Files_Create,
  Files_Free,
  Files_CreateFile,
  Files_OpenFile,
  Files_RewriteFile,
  Files_AppendFile,
  Files_DeleteFile,
  Files_RenameFile,
  Files_CloseFile,
  Files_WriteINI,
  Files_ReadINI,
  Files_DeleteINI,
  Files_EndOfFile,
  Files_FileSize,
  Files_ReadFileString,
  Files_WriteFileString,
  Files_SetFileCharPointer,
  Files_FilePointerPos;
