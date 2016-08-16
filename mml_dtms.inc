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

    DTM wrappers for libMML.
}

{%MainUnit mml.lpr}

function DTM_Create(): Pointer; extdecl
begin
  Result := TMDTM.Create();
end;

procedure DTM_Free(Client: Pointer); extdecl
begin
  TMDTM(Client).Free;
end;

      {Name : string;
      Index : integer;
      function ToString : string;
      function SaveToFile(const FileName : string) : boolean;
      function LoadFromString(const s : string) : boolean;
      procedure Normalize;
      function Valid : boolean;
      procedure DeletePoint(Point : integer);
      procedure SwapPoint(p1, p2: integer);
      procedure MovePoint(fromIndex, toIndex: integer);
      function AddPoint(Point: TMDTMPoint): integer;
      property PPoints : PMDTMPoint read GetPointerPoints;
      property Count : integer read FLen write SetPointCount;
      property Points : TMDTMPointArray read FPoints;}

    {TMDTMS = class(TObject) //Manages the DTMs   TMufasaDTMs
    private
      Client: TObject;
      DTMList: Array Of TMDTM;
      FreeSpots: Array Of Integer;
      procedure CheckIndex(index : integer);
    public
      function AddDTM(const d: TSDTM): Integer;overload;
      function AddDTM(const d: TMDTM): Integer;overload;
	  function ExistsDTM(index : integer) : boolean;
      function GetDTM(index: Integer) :TMDTM;
      procedure FreeDTM(DTM: Integer);
      function StringToDTM(const S: String): Integer;
      property DTM[Index : integer]: TMDTM read GetDTM; default;
      constructor Create(Owner: TObject);
      destructor Destroy; override;
    end;}


exports
  DTM_Create,
  DTM_Free;
