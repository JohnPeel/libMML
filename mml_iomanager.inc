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

    IOManager wrappers for libMML.
}

{%MainUnit mml.lpr}

function IOManager_Create(plugin_dir: shortstring): Pointer; cdecl;
begin
  if (plugin_dir <> '') then
    Result := TIOManager.Create(plugin_dir)
  else
    Result := TIOManager.Create();
end;

procedure IOManager_Free(IOManager: Pointer); cdecl;
begin
  TIOManager(IOManager).Free;
end;

function IOManager_GetError(IOManager: Pointer): shortstring; cdecl;
begin
  Result := TIOManager(IOManager).GetError();
end;

function IOManager_ReceivedError(IOManager: Pointer): Boolean; cdecl;
begin
  Result := TIOManager(IOManager).ReceivedError;
end;

procedure IOManager_ResetError(IOManager: Pointer); cdecl;
begin
  TIOManager(IOManager).ResetError();
end;

procedure IOManager_SetDesktop(IOManager: Pointer); cdecl;
begin
  TIOManager(IOManager).SetDesktop();
end;

function IOManager_SetTarget(IOManager: Pointer; ArrPtr: PRGB32; Size: TPoint): integer; cdecl;
begin
  Result := TIOManager(IOManager).SetTarget(ArrPtr, Size);
end;

function IOManager_SetBitmapTarget(IOManager: Pointer; MBmp: Pointer): integer; cdecl;
begin
  Result := TIOManager(IOManager).SetTarget(TMufasaBitmap(MBmp));
end;

function IOManager_SetNamedTarget(IOManager: Pointer; name, initargs: shortstring): integer; cdecl;
begin
  Result := TIOManager(IOManager).SetTarget(name, initargs);
end;

function IOManager_TargetValid(IOManager: Pointer): Boolean; cdecl;
begin
  Result := TIOManager(IOManager).TargetValid;
end;

procedure IOManager_BitmapDestroyed(IOManager: Pointer; MBmp: Pointer); cdecl;
begin
  TIOManager(IOManager).BitmapDestroyed(TMufasaBitmap(MBmp));
end;

function IOManager_GetColor(IOManager: Pointer; x, y: integer): TColor; cdecl;
begin
  Result := TIOManager(IOManager).GetColor(x, y);
end;

function IOManager_ReturnData(IOManager: Pointer; xs, ys, width, height: Integer): TRetData; cdecl;
begin
  Result := TIOManager(IOManager).ReturnData(xs, ys, width, height);
end;

procedure IOManager_FreeReturnData(IOManager: Pointer); cdecl;
begin
  TIOManager(IOManager).FreeReturnData();
end;

procedure IOManager_GetDimensions(IOManager: Pointer; out W, H: Integer); cdecl;
begin
  TIOManager(IOManager).GetDimensions(W, H);
end;

procedure IOManager_GetPosition(IOManager: Pointer; var Left, Top: Integer); cdecl;
begin
  TIOManager(IOManager).GetPosition(Left, Top);
end;

procedure IOManager_ActivateClient(IOManager: Pointer); cdecl;
begin
  TIOManager(IOManager).ActivateClient();
end;

function IOManager_IsFrozen(IOManager: Pointer): boolean; cdecl;
begin
  Result := TIOManager(IOManager).IsFrozen();
end;

procedure IOManager_SetFrozen(IOManager: Pointer; makefrozen: boolean); cdecl;
begin
  TIOManager(IOManager).SetFrozen(makefrozen);
end;

function IOManager_MouseSetClientArea(IOManager: Pointer; x1, y1, x2, y2: integer): boolean; cdecl;
begin
  Result := TIOManager(IOManager).MouseSetClientArea(x1, y1, x2, y2);
end;

procedure IOManager_MouseResetClientArea(IOManager: Pointer); cdecl;
begin
  TIOManager(IOManager).MouseResetClientArea();
end;

function IOManager_ImageSetClientArea(IOManager: Pointer; x1, y1, x2, y2: integer): boolean; cdecl;
begin
  Result := TIOManager(IOManager).ImageSetClientArea(x1, y1, x2, y2);
end;

procedure IOManager_ImageResetClientArea(IOManager: Pointer); cdecl;
begin
  TIOManager(IOManager).ImageResetClientArea();
end;

procedure IOManager_GetMousePos(IOManager: Pointer; var X, Y: Integer); cdecl;
begin
  TIOManager(IOManager).GetMousePos(X, Y);
end;

procedure IOManager_MoveMouse(IOManager: Pointer; X, Y: Integer); cdecl;
begin
  TIOManager(IOManager).MoveMouse(X, Y);
end;

procedure IOManager_ScrollMouse(IOManager: Pointer; x,y : integer; Lines : integer); cdecl;
begin
  TIOManager(IOManager).ScrollMouse(X, Y, Lines);
end;

procedure IOManager_HoldMouse(IOManager: Pointer; x,y : integer; button: TClickType); cdecl;
begin
  TIOManager(IOManager).HoldMouse(x, y, button);
end;

procedure IOManager_ReleaseMouse(IOManager: Pointer; x,y : integer; button: TClickType); cdecl;
begin
  TIOManager(IOManager).ReleaseMouse(x, y, button);
end;

procedure IOManager_ClickMouse(IOManager: Pointer; X, Y: Integer; button: TClickType); cdecl;
begin
  TIOManager(IOManager).ClickMouse(x, y, button);
end;

function  IOManager_IsMouseButtonDown(IOManager: Pointer; button : TClickType) : boolean; cdecl;
begin
  Result := TIOManager(IOManager).IsMouseButtonDown(button);
end;

procedure IOManager_KeyUp(IOManager: Pointer; key: Word); cdecl;
begin
  TIOManager(IOManager).KeyUp(key);
end;

procedure IOManager_KeyDown(IOManager: Pointer; key: Word); cdecl;
begin
  TIOManager(IOManager).KeyDown(key);
end;

procedure IOManager_PressKey(IOManager: Pointer; key: Word); cdecl;
begin
  TIOManager(IOManager).PressKey(key);
end;

procedure IOManager_SendText(IOManager: Pointer; text: string; keywait, keymodwait: integer); cdecl;
begin
  TIOManager(IOManager).SendText(text, keywait, keymodwait);
end;

function IOManager_isKeyDown(IOManager: Pointer; key: Word): Boolean; cdecl;
begin
  Result := TIOManager(IOManager).isKeyDown(key);
end;

function IOManager_GetKeyCode(IOManager: Pointer; c : char) : integer; cdecl;
begin
  Result := TIOManager(IOManager).GetKeyCode(c);
end;

function IOManager_GetImageTarget(IOManager: Pointer): Pointer; cdecl;
begin
  Result := TIOManager(IOManager).GetImageTarget();
end;

function IOManager_GetKeyMouseTarget(IOManager: Pointer): Pointer; cdecl;
begin
  Result := TIOManager(IOManager).GetKeyMouseTarget();
end;

function IOManager_ExportImageTarget(IOManager: Pointer): TTarget_Exported; cdecl;
begin
  Result := TIOManager(IOManager).ExportImageTarget();
end;

function IOManager_ExportKeyMouseTarget(IOManager: Pointer): TTarget_Exported; cdecl;
begin
  Result := TIOManager(IOManager).ExportKeyMouseTarget();
end;

procedure IOManager_GetImageTargetIdx(IOManager: Pointer; var idx: integer); cdecl;
begin
  TIOManager(IOManager).GetImageTarget(idx);
end;

procedure IOManager_GetKeyMouseTargetIdx(IOManager: Pointer; var idx: integer); cdecl;
begin
  TIOManager(IOManager).GetKeyMouseTarget(idx);
end;

procedure IOManager_SetImageTarget(IOManager: Pointer; idx: integer); cdecl;
begin
  TIOManager(IOManager).SetImageTarget(idx);
end;

procedure IOManager_SetKeyMouseTarget(IOManager: Pointer; idx: integer); cdecl;
begin
  TIOManager(IOManager).SetKeyMouseTarget(idx);
end;

procedure IOManager_FreeTarget(IOManager: Pointer; idx: integer); cdecl;
begin
  TIOManager(IOManager).FreeTarget(idx);
end;

procedure IOManager_SetState(IOManager: Pointer; val: Boolean); cdecl;
begin
  TIOManager(IOManager).SetState(val);
end;

function IOManager_GetProcesses(IOManager: Pointer): TSysProcArr; cdecl;
begin
  Result := TIOManager(IOManager).GetProcesses();
end;

procedure IOManager_SetProcTarget(IOManager: Pointer; Proc: TSysProc); cdecl;
begin
  TIOManager(IOManager).SetTargetEx(Proc);
end;


exports
  IOManager_Create,
  IOManager_Free,
  IOManager_GetError,
  IOManager_ReceivedError,
  IOManager_ResetError,
  IOManager_SetDesktop,
  IOManager_SetTarget,
  IOManager_SetBitmapTarget,
  IOManager_SetNamedTarget,
  IOManager_TargetValid,
  IOManager_BitmapDestroyed,
  IOManager_GetColor,
  IOManager_ReturnData,
  IOManager_FreeReturnData,
  IOManager_GetDimensions,
  IOManager_GetPosition,
  IOManager_ActivateClient,
  IOManager_IsFrozen,
  IOManager_SetFrozen,
  IOManager_MouseSetClientArea,
  IOManager_MouseResetClientArea,
  IOManager_ImageSetClientArea,
  IOManager_ImageResetClientArea,
  IOManager_GetMousePos,
  IOManager_MoveMouse,
  IOManager_ScrollMouse,
  IOManager_HoldMouse,
  IOManager_ReleaseMouse,
  IOManager_ClickMouse,
  IOManager_IsMouseButtonDown,
  IOManager_KeyUp,
  IOManager_KeyDown,
  IOManager_PressKey,
  IOManager_SendText,
  IOManager_isKeyDown,
  IOManager_GetKeyCode,
  IOManager_GetImageTarget,
  IOManager_GetKeyMouseTarget,
  IOManager_ExportImageTarget,
  IOManager_ExportKeyMouseTarget,
  IOManager_GetImageTargetIdx,
  IOManager_GetKeyMouseTargetIdx,
  IOManager_SetImageTarget,
  IOManager_SetKeyMouseTarget,
  IOManager_FreeTarget,
  IOManager_SetState,
  IOManager_GetProcesses,
  IOManager_SetProcTarget;
