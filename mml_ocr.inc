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

    OCR wrappers for libMML.
}

{%MainUnit mml.lpr}

function OCR_Create(Client: Pointer): Pointer; extdecl
begin
  Result := TMOCR.Create(TClient(Client));
end;

procedure OCR_Free(OCR: Pointer); extdecl
begin
  TMOCR(OCR).Free;
end;

procedure OCR_SetPath(OCR: Pointer; const path: PChar); extdecl
begin
  TMOCR(OCR).SetPath(path);
end;

function OCR_InitTOCR(OCR: Pointer; const path: PChar): boolean; extdecl
begin
  Result := TMOCR(OCR).InitTOCR(path);
end;

function OCR_getTextPointsIn(OCR: Pointer; sx, sy, w, h: Integer; shadow: boolean; var _chars, _shadows: T2DPointArray): Boolean; extdecl
begin
  Result := TMOCR(OCR).getTextPointsIn(sx, sy, w, h, shadow, _chars, _shadows);
end;

function OCR_GetUpTextAtEx(OCR: Pointer; atX, atY: integer; shadow: boolean; fontname: shortstring): shortstring; extdecl
begin
  Result := TMOCR(OCR).GetUpTextAtEx(atX, atY, shadow, fontname);
end;

function OCR_GetUpTextAt(OCR: Pointer; atX, atY: integer; shadow: boolean): shortstring; extdecl
begin
  Result := TMOCR(OCR).GetUpTextAt(atX, atY, shadow);
end;

procedure OCR_CreateDefaultFilter(OCR: Pointer); extdecl
begin
  TMOCR(OCR).CreateDefaultFilter();
end;

procedure OCR_SetFilter(OCR: Pointer; filter: TOCRFilterDataArray); extdecl
begin
  TMOCR(OCR).SetFilter(filter);
end;

procedure OCR_ResetFilter(OCR: Pointer); extdecl
begin
  TMOCR(OCR).ResetFilter();
end;

procedure OCR_FilterUpTextByColour(OCR: Pointer; bitmap: Pointer); extdecl
begin
  TMOCR(OCR).FilterUpTextByColour(bitmap);
end;

procedure OCR_FilterUpTextByCharacteristics(OCR: Pointer; bitmap: Pointer); extdecl
begin
  TMOCR(OCR).FilterUpTextByCharacteristics(bitmap);
end;

procedure OCR_FilterUpTextByColourMatches(OCR: Pointer; bitmap: Pointer); extdecl
begin
  TMOCR(OCR).FilterUpTextByColourMatches(bitmap);
end;

procedure OCR_FilterShadowBitmap(OCR: Pointer; bitmap: Pointer); extdecl
begin
  TMOCR(OCR).FilterShadowBitmap(bitmap);
end;

procedure OCR_FilterCharsBitmap(OCR: Pointer; bitmap: Pointer); extdecl
begin
  TMOCR(OCR).FilterCharsBitmap(bitmap);
end;

function OCR_GetTextAt(OCR: Pointer; atX, atY, minvspacing, maxvspacing, hspacing, color, tol, len: integer; font: shortstring): shortstring; extdecl
begin
  Result := TMOCR(OCR).GetTextAt(atX, atY, minvspacing, maxvspacing, hspacing, color, tol, len, font);
end;

function OCR_GetTextAtBox(OCR: Pointer; xs, ys, xe, ye, minvspacing, maxvspacing, hspacing, color, tol: integer; font: shortstring): shortstring; extdecl
begin
  Result := TMOCR(OCR).GetTextAt(xs, ys, xe, ye, minvspacing, maxvspacing, hspacing, color, tol, font);
end;

function OCR_GetTextATPA(OCR: Pointer; const ATPA: T2DPointArray; const maxvspacing: integer; font: shortstring): shortstring; extdecl
begin
  Result := TMOCR(OCR).GetTextATPA(ATPA, maxvspacing, font);
end;

function OCR_TextToFontTPA(OCR: Pointer; Text, font: shortstring; out w, h: integer): TPointArray; extdecl
begin
  Result := TMOCR(OCR).TextToFontTPA(Text, font, w, h);
end;

function OCR_TextToFontBitmap(OCR: Pointer; Text, font: shortstring): TMufasaBitmap; extdecl
begin
  Result := TMOCR(OCR).TextToFontBitmap(Text, font);
end;

function OCR_TextToMask(OCR: Pointer; Text, font: shortstring): TMask; extdecl
begin
  Result := TMOCR(OCR).TextToMask(Text, font);
end;

procedure OCR_setFonts(OCR: Pointer; Fonts: Pointer); extdecl
begin
  TMOCR(OCR).Fonts := TMFonts(Fonts);
end;

function OCR_getFonts(OCR: Pointer): Pointer; extdecl
begin
  Result := TMOCR(OCR).Fonts;
end;

exports
  OCR_Create,
  OCR_Free;
