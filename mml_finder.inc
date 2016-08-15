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

    Finder wrappers for libMML.
}

{%MainUnit mml.lpr}

function Finder_Create(Client: Pointer): Pointer; cdecl;
begin
  Result := TMFinder.Create(TClient(Client));
end;

procedure Finder_Free(Finder: Pointer); cdecl;
begin
  TMFinder(Finder).Free;
end;

procedure Finder_setWarnOnly(Finder: Pointer; val: boolean); cdecl;
begin
  TMFinder(Finder).WarnOnly := val;
end;

procedure Finder_DefaultOperations(Finder: Pointer; var xs, ys, xe, ye: integer); cdecl;
begin
  TMFinder(Finder).DefaultOperations(xs, ys, xe, ye);
end;

function Finder_CountColorTolerance(Finder: Pointer; Color, xs, ys, xe, ye, Tolerance: Integer): Integer; cdecl;
begin
  Result := TMFinder(Finder).CountColorTolerance(Color, xs, ys, xe, ye, Tolerance);
end;

function Finder_CountColor(Finder: Pointer; Color, xs, ys, xe, ye: Integer): Integer; cdecl;
begin
  Result := TMFinder(Finder).CountColor(Color, xs, ys, xe, ye);
end;

function Finder_SimilarColors(Finder: Pointer; Color1, Color2, Tolerance: Integer) : boolean; cdecl;
begin
  Result := TMFinder(Finder).SimilarColors(Color1, Color2, Tolerance);
end;

function Finder_FindColor(Finder: Pointer; out x, y: Integer; Color, xs, ys, xe, ye: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindColor(x, y, Color, xs, ys, xe, ye);
end;

function Finder_FindColorSpiral(Finder: Pointer; var x, y: Integer; color, xs, ys, xe, ye: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindColorSpiral(x, y, color, xs, ys, xe, ye);
end;

function Finder_FindColorSpiralTolerance(Finder: Pointer; var x, y: Integer; color, xs, ys, xe, ye,Tol: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindColorSpiralTolerance(x, y, color, xs, ys, xe, ye, Tol);
end;

function Finder_FindColorTolerance(Finder: Pointer; out x, y: Integer; Color, xs, ys, xe, ye, tol: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindColorTolerance(x, y, Color, xs, ys, xe, ye, tol);
end;

function Finder_FindColorsTolerance(Finder: Pointer; out Points: TPointArray; Color, xs, ys, xe, ye, Tol: Integer): Boolean; cdecl;
begin                          // HINT: Might need fixing, Is TPointArray a dynamic array or a open array?
  Result := TMFinder(Finder).FindColorsTolerance(Points, Color, xs, ys, xe, ye, Tol);
end;

function Finder_FindColorsSpiralTolerance(Finder: Pointer; x, y: Integer; out Points: TPointArray; color, xs, ys, xe, ye: Integer; Tol: Integer) : boolean; cdecl;
begin
  Result := TMFinder(Finder).FindColorsSpiralTolerance(x, y, Points, color, xs, ys, xe, ye, Tol);
end;

function Finder_FindColors(Finder: Pointer; var TPA: TPointArray; Color, xs, ys, xe, ye: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindColors(TPA, Color, xs, ys, xe, ye);
end;

function Finder_FindColoredArea(Finder: Pointer; var x, y: Integer; color, xs, ys, xe, ye: Integer; MinArea: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindColoredArea(x, y, color, xs, ys, xe, ye, MinArea);
end;

function Finder_FindColoredAreaTolerance(Finder: Pointer; var x, y: Integer; color, xs, ys, xe, ye: Integer; MinArea, tol: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindColoredAreaTolerance(x, y, color, xs, ys, xe, ye, MinArea, tol);
end;

function Finder_FindMaskTolerance(Finder: Pointer; const mask: TMask; out x, y: Integer; xs, ys, xe, ye: Integer; Tolerance, ContourTolerance: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindMaskTolerance(mask, x, y, xs, ys, xe, ye, Tolerance, ContourTolerance);
end;
procedure Finder_CheckMask(Finder: Pointer; const Mask: TMask); cdecl;
begin
  TMFinder(Finder).CheckMask(Mask);
end;

function Finder_FindBitmap(Finder: Pointer; bitmap: Pointer; out x, y: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindBitmap(TMufasaBitmap(bitmap), x, y);
end;

function Finder_FindBitmapIn(Finder: Pointer; bitmap: Pointer; out x, y: Integer;  xs, ys, xe, ye: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindBitmapIn(TMufasaBitmap(bitmap), x, y, xs, ys, xe, ye);
end;

function Finder_FindBitmapToleranceIn(Finder: Pointer; bitmap: Pointer; out x, y: Integer; xs, ys, xe, ye: Integer; tolerance: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindBitmapToleranceIn(TMufasaBitmap(bitmap), x, y, xs, ys, xe, ye, tolerance);
end;

function Finder_FindBitmapSpiral(Finder: Pointer; bitmap: Pointer; var x, y: Integer; xs, ys, xe, ye: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindBitmapSpiral(TMufasaBitmap(bitmap), x, y, xs, ys, xe, ye);
end;

function Finder_FindBitmapSpiralTolerance(Finder: Pointer; bitmap: Pointer; var x, y: Integer; xs, ys, xe, ye,tolerance : integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindBitmapSpiralTolerance(TMufasaBitmap(bitmap), x, y, xs, ys, xe, ye, tolerance);
end;

function Finder_FindBitmapsSpiralTolerance(Finder: Pointer; bitmap: Pointer; x, y: Integer; out Points : TPointArray; xs, ys, xe, ye,tolerance: Integer; maxToFind: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindBitmapsSpiralTolerance(TMufasaBitmap(bitmap), x, y, Points, xs, ys, xe, ye, tolerance, maxToFind);
end;

function Finder_FindDeformedBitmapToleranceIn(Finder: Pointer; bitmap: Pointer; out x, y: Integer; xs, ys, xe, ye: Integer; tolerance: Integer; Range: Integer; AllowPartialAccuracy: Boolean; out accuracy: Extended): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindDeformedBitmapToleranceIn(TMufasaBitmap(bitmap), x, y, xs, ys, xe, ye, tolerance, Range, AllowPartialAccuracy, accuracy);
end;

function Finder_FindDTM(Finder: Pointer; DTM: Pointer; out x, y: Integer; x1, y1, x2, y2: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindDTM(TMDTM(DTM), x, y, x1, y1, x2, y2);
end;

function Finder_FindDTMs(Finder: Pointer; DTM: Pointer; out Points: TPointArray; x1, y1, x2, y2 : integer; maxToFind: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindDTMs(TMDTM(DTM), Points, x1, y1, x2, y2, maxToFind);
end;

function Finder_FindDTMRotated(Finder: Pointer; DTM: Pointer; out x, y: Integer; x1, y1, x2, y2: Integer; sAngle, eAngle, aStep: Extended; out aFound: Extended; Alternating : boolean): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindDTMRotated(TMDTM(DTM), x, y, x1, y1, x2, y2, sAngle, eAngle, aStep, aFound, Alternating);
end;

function Finder_FindDTMsRotated(Finder: Pointer; DTM: Pointer; out Points: TPointArray; x1, y1, x2, y2: Integer; sAngle, eAngle, aStep: Extended; out aFound: T2DExtendedArray;Alternating : boolean; maxToFind: Integer): Boolean; cdecl;
begin
  Result := TMFinder(Finder).FindDTMsRotated(TMDTM(DTM), Points, x1, y1, x2, y2, sAngle, eAngle, aStep, aFound, Alternating, maxToFind);
end;

procedure Finder_GetColors(Finder: Pointer; Coords: TPointArray; out Result: TIntegerArray); cdecl;
begin
  Result := TMFinder(Finder).GetColors(Coords);
end;

procedure Finder_SetToleranceSpeed(Finder: Pointer; nCTS: Integer); cdecl;
begin
  TMFinder(Finder).SetToleranceSpeed(nCTS);
end;

function Finder_GetToleranceSpeed(Finder: Pointer): Integer; cdecl;
begin
  Result := TMFinder(Finder).GetToleranceSpeed();
end;

procedure Finder_SetToleranceSpeed2Modifiers(Finder: Pointer; const nHue, nSat: Extended); cdecl;
begin
  TMFinder(Finder).SetToleranceSpeed2Modifiers(nHue, nSat);
end;

procedure Finder_GetToleranceSpeed2Modifiers(Finder: Pointer; out hMod, sMod: Extended); cdecl;
begin
  TMFinder(Finder).GetToleranceSpeed2Modifiers(hMod, sMod);
end;

procedure Finder_SetToleranceSpeed3Modifier(Finder: Pointer; modifier: Extended); cdecl;
begin
  TMFinder(Finder).SetToleranceSpeed3Modifier(modifier);
end;

function Finder_GetToleranceSpeed3Modifier(Finder: Pointer): Extended; cdecl;
begin
  Result := TMFinder(Finder).GetToleranceSpeed3Modifier();
end;

function Finder_CreateCTSInfo(Finder: Pointer; Color, Tolerance: Integer): Pointer; cdecl;
begin
  Result := TMFinder(Finder).Create_CTSInfo(Color, Tolerance);
end;

function Finder_CreateCTSInfoRGB(Finder: Pointer; R, G, B, Tolerance: Integer): Pointer; cdecl;
begin
  Result := TMFinder(Finder).Create_CTSInfo(R, G, B, Tolerance);
end;

{procedure Finder_CreateCTSInfoArray(Finder: Pointer; color: array of integer; tolerance: array of integer; out Result: TCTSInfoArray); cdecl;
begin
  Result := TMFinder(Finder).Create_CTSInfoArray(color, tolerance); // ERROR: Illegal Expression
end;

procedure Finder_CreateCTSInfo2DArray(Finder: Pointer; w, h: integer; data: TPRGB32Array; Tolerance: Integer; out Result: TCTSInfo2DArray); cdecl;
begin
  Result := TMFinder(Finder).Create_CTSInfo2DArray(w, h, data, Tolerance);
end;}

exports
  Finder_Create,
  Finder_Free,
  Finder_setWarnOnly,
  Finder_DefaultOperations,
  Finder_CountColorTolerance,
  Finder_CountColor,
  Finder_SimilarColors,
  Finder_FindColor,
  Finder_FindColorSpiral,
  Finder_FindColorSpiralTolerance,
  Finder_FindColorTolerance,
  Finder_FindColorsTolerance,
  Finder_FindColorsSpiralTolerance,
  Finder_FindColors,
  Finder_FindColoredArea,
  Finder_FindColoredAreaTolerance,
  Finder_FindMaskTolerance,
  Finder_CheckMask,
  Finder_FindBitmap,
  Finder_FindBitmapIn,
  Finder_FindBitmapToleranceIn,
  Finder_FindBitmapSpiral,
  Finder_FindBitmapSpiralTolerance,
  Finder_FindBitmapsSpiralTolerance,
  Finder_FindDeformedBitmapToleranceIn,
  Finder_FindDTM,
  Finder_FindDTMs,
  Finder_FindDTMRotated,
  Finder_FindDTMsRotated,
  Finder_GetColors,
  Finder_SetToleranceSpeed,
  Finder_GetToleranceSpeed,
  Finder_SetToleranceSpeed2Modifiers,
  Finder_GetToleranceSpeed2Modifiers,
  Finder_SetToleranceSpeed3Modifier,
  Finder_GetToleranceSpeed3Modifier,
  Finder_CreateCTSInfo,
  Finder_CreateCTSInfoRGB;
