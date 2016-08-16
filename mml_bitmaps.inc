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

    Bitmap wrappers for libMML.
}

{%MainUnit mml.lpr}

function Bitmap_Create(): Pointer; extdecl
begin
  Result := TMufasaBitmap.Create();
end;

procedure Bitmap_Free(Bitmap: Pointer); extdecl
begin
  TMufasaBitmap(Bitmap).Free;
end;

    {OnDestroy : procedure(Bitmap : TMufasaBitmap) of object;
    //FakeData : array of TRGB32;
    FData : PRGB32;
    property Name : string read FName write FName;
    property Index : integer read FIndex write FIndex;

    procedure SetSize(AWidth,AHeight : integer);
    procedure StretchResize(AWidth,AHeight : integer);
    procedure ResizeEx(Method: TBmpResizeMethod; NewWidth, NewHeight: integer);

    property Width : Integer read w;
    property Height : Integer read h;

    procedure SetPersistentMemory(mem: PtrUInt; awidth, aheight: integer);
    procedure ResetPersistentMemory;

    function PointInBitmap(x,y : integer) : boolean;
    procedure ValidatePoint(x,y : integer);
    function SaveToFile(const FileName : string) :boolean;
    procedure LoadFromFile(const FileName : string);
    procedure Rectangle(const Box : TBox;FillCol : TColor);
    procedure Rectangle(const Box: TBox; const Color: Integer; const Transparency: Extended); overload;
    procedure FloodFill(const StartPT : TPoint; const SearchCol, ReplaceCol : TColor);
    procedure FastSetPixel(x,y : integer; Color : TColor);
    procedure FastSetPixels(Points : TPointArray; Colors : TIntegerArray);
    procedure DrawATPA(ATPA : T2DPointArray; Colors : TIntegerArray);overload;
    procedure DrawATPA(ATPA : T2DPointArray);overload;
    procedure DrawTPA(Points : TPointArray; Color : TColor);
    procedure DrawToCanvas(x,y : integer; Canvas : TCanvas);
    procedure LineTo(Src,Dst: TPoint;Color: TColor);
    function FindColors(var points: TPointArray; const color: integer): boolean;
    function FastGetPixel(x,y : integer) : TColor;
    function FastGetPixels(Points : TPointArray) : TIntegerArray;
    function GetAreaColors(xs,ys,xe,ye : integer) : T2DIntArray;
    function GetColors: TIntegerArray;
    function GetHSLValues(xs, ys, xe, ye: integer): T2DHSLArray;
    procedure FastDrawClear(Color : TColor);
    procedure FastDrawTransparent(x, y: Integer; TargetBitmap: TMufasaBitmap);
    procedure FastReplaceColor(OldColor, NewColor: TColor);
    procedure CopyClientToBitmap(MWindow : TObject;Resize : boolean; xs, ys, xe, ye: Integer);overload;
    procedure CopyClientToBitmap(MWindow : TObject;Resize : boolean;x,y : integer; xs, ys, xe, ye: Integer);overload;
    procedure RotateBitmap(angle: Extended; TargetBitmap: TMufasaBitmap);
    procedure RotateBitmapEx(Angle: Single; Expand: Boolean; Smooth: Boolean; TargetBitmap: TMufasaBitmap);
    procedure Desaturate(TargetBitmap : TMufasaBitmap); overload;
    procedure Desaturate;overload;
    procedure GreyScale(TargetBitmap : TMufasaBitmap);overload;
    procedure GreyScale;
    procedure Brightness(TargetBitmap : TMufasaBitmap; br : integer); overload;
    procedure Brightness(br: integer);overload;
    procedure Contrast(TargetBitmap : TMufasaBitmap; co : Extended);overload;
    procedure Contrast(co: Extended);overload;
    procedure Invert(TargetBitmap : TMufasaBitmap);overload;
    procedure Invert;overload;
    procedure Posterize(TargetBitmap : TMufasaBitmap; Po : integer);overload;
    procedure Posterize(Po : integer);overload;
    procedure Convolute(TargetBitmap : TMufasaBitmap; Matrix : T2DExtendedArray);
    function Copy(const xs,ys,xe,ye : integer) : TMufasaBitmap; overload;
    function Copy: TMufasaBitmap;overload;
    procedure Blur(const Block, xs, ys, xe, ye: integer);
    procedure Blur(const Block: integer); overload;
    procedure Crop(const xs, ys, xe, ye: integer);
    function ToTBitmap: TBitmap;
    function ToString : string; override;
    function ToMatrix: T2DIntegerArray;
    procedure DrawMatrix(const matrix: T2DIntegerArray);
    procedure ThresholdAdaptive(Alpha, Beta: Byte; InvertIt: Boolean; Method: TBmpThreshMethod; C: Integer);
    function RowPtrs : TPRGB32Array;
    procedure LoadFromTBitmap(bmp: TBitmap);
    procedure LoadFromRawImage(RawImage: TRawImage);
    function CreateTMask : TMask;
    procedure ResizeBilinear(NewW, NewH: Integer);
    procedure DrawText(const Text, FontName: string; const pnt: TPoint; const Shadow: Boolean; const Color: Integer);
    procedure DrawSystemText(const Text, FontName: string; const FontSize: Integer; const pnt: TPoint; const Shadow: Boolean; const Color: Integer);
    procedure SetTransparentColor(Col : TColor);
    function GetTransparentColor : TColor;
    property TransparentColorSet : boolean read FTransparentSet;
    property List: TMBitmaps read FList write FList;
    procedure SetAlphaValue(const value : byte);}

function Bitmaps_Create(Client: Pointer): Pointer; extdecl
begin
  Result := TMBitmaps.Create(TClient(Client));
end;

procedure Bitmaps_Free(Bitmaps: Pointer); extdecl
begin
  TMBitmaps(Bitmaps).Free;
end;

function Bitmaps_getBitmap(Bitmaps: Pointer; Index: integer): Pointer; extdecl
begin
  Result := TMBitmaps(Bitmaps).GetBMP(Index);
end;

function Bitmaps_createBitmap(Bitmaps: Pointer; width, height: integer): integer; extdecl
begin
  Result := TMBitmaps(Bitmaps).CreateBMP(width, height);
end;

function Bitmaps_existsBitmap(Bitmaps: Pointer; Index: integer): Boolean; extdecl
begin
  Result := TMBitmaps(Bitmaps).ExistsBMP(Index);
end;

function Bitmaps_addBitmap(Bitmaps: Pointer; Bitmap: Pointer): integer; extdecl
begin
  Result := TMBitmaps(Bitmaps).AddBMP(TMufasaBitmap(Bitmap));
end;

function Bitmaps_copyBitmap(Bitmaps: Pointer; Index: integer): integer; extdecl
begin
  Result := TMBitmaps(Bitmaps).CopyBMP(Index);
end;

function Bitmaps_createMirroredBitmap(Bitmaps: Pointer; Index: Integer; MirrorStyle: TBmpMirrorStyle): integer; extdecl
begin
  Result := TMBitmaps(Bitmaps).CreateMirroredBitmap(Index, MirrorStyle);
end;

function Bitmaps_createBMPFromFile(Bitmaps: Pointer; const Path: shortstring): integer; extdecl
begin
  Result := TMBitmaps(Bitmaps).CreateBMPFromFile(Path);
end;

function Bitmaps_createBMPFromString(Bitmaps: Pointer; Name: shortstring; width, height: integer; Data: PChar): integer; extdecl
begin
  Result := TMBitmaps(Bitmaps).CreateBMPFromString(Name, width, height, Data);
end;

function Bitmaps_removeBMP(Bitmaps: Pointer; Index: integer): Pointer; extdecl
begin
  Result := TMBitmaps(Bitmaps).RemoveBMP(Index);
end;

exports
  Bitmap_Create,
  Bitmap_Free,

  Bitmaps_Create,
  Bitmaps_Free,
  Bitmaps_getBitmap,
  Bitmaps_createBitmap,
  Bitmaps_existsBitmap,
  Bitmaps_addBitmap,
  Bitmaps_copyBitmap,
  Bitmaps_createMirroredBitmap,
  Bitmaps_createBMPFromFile,
  Bitmaps_createBMPFromString,
  Bitmaps_removeBMP;
