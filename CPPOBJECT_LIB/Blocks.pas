﻿
 //**************************************************************************//
 // Данный исходный код является составной частью системы МВТУ-4             //
 // Программист:        Никишин Е.В.                                        //
 //**************************************************************************//


unit Blocks;

 //***************************************************************************//
 //  Блоки для обмена данными через последовательный интерфейс ARNIC 429      //
 //***************************************************************************//

interface

uses
     Classes
   , DataTypes
   , RunObjts
   , Winapi.Windows
   ;

type
  // Блок - встроенный клиент OPC
  // по умолчанию настроен на тестовый сервер Matricon
  TCppObjectBlock = class(TRunObject)
  public
    constructor  Create(Owner: TObject);override;
    destructor   Destroy;override;
    function     InfoFunc(Action: integer;aParameter: NativeInt):NativeInt;override;
    function     RunFunc(var at,h : RealType;Action:Integer):NativeInt;override;
    function     GetParamID(const ParamName:string;var DataType:TDataType;var IsConst: boolean):NativeInt;override;
    procedure    RestartSave(Stream: TStream);override;
    function     RestartLoad(Stream: TStream;Count: integer;const TimeShift:double):boolean;override;
    procedure    EditFunc(Props:TList;
                          SetPortCount:TSetPortCount;
                          SetCondPortCount:TSetCondPortCount;
                          ExecutePropScript:TExecutePropScript
                          ); override;

  strict private
    m_nextTime: double; // Целевое время

  end;

implementation

uses
     Info
   , SysUtils
   , CppObject_texts
   , IntArrays
   , RealArrays
   , uByteOperations
   , DataObjts
   , InterfaceUnit
   , StrUtils
   ;

//*****  Внешние методы *****

constructor  TCppObjectBlock.Create;
begin
  inherited;
end;

destructor   TCppObjectBlock.Destroy;
begin
  inherited;
end;

function TCppObjectBlock.InfoFunc(Action: integer;aParameter: NativeInt):NativeInt;
var
  elementInfo : TElementInfo;
  List : TArray<String>;
  trimStr : String;
begin
  Result := 0;
  case Action of
    i_GetBlockType: begin
      Result:=t_fun;
    end;
    i_GetCount: begin

    end;
    i_GetInit: begin
      //По умолчанию блок - приоритетный, т.к. он полностью асинхронный
      Result:=1;
    end;
    i_HaveSpetialEditor : begin
      //  Берем имя файла библиотеки
      DllInfo.Main.GetElementInfo(VisualObject, elementInfo);
      List := elementInfo.CalcTemplate^.Split([#$D#$A]);
      if Length(List) < 4 then begin
        ErrorEvent(txtCppObj_er_NoSetDll, msError, VisualObject);
        Exit;
      end;
    end
    
  else
    Result:=inherited InfoFunc(Action,aParameter);
  end;
end;

function TCppObjectBlock.RunFunc;
begin
 Result := r_Success;
  case Action of
    f_Stop: begin
     
    end;
    f_InitObjects: begin
     
    end;
    f_InitState: begin
      
    end;
    f_GoodStep: begin
      
    end;
  end;
end;

function TCppObjectBlock.GetParamID(const ParamName:string;var DataType:TDataType;var IsConst: boolean):NativeInt;
begin
  Result:=inherited GetParamId(ParamName,DataType,IsConst);
  if Result = -1 then begin
    
  end;
end;

procedure TCppObjectBlock.RestartSave(Stream: TStream);
begin
  inherited;
  Stream.Write(m_nextTime, SizeOf(double));
end;

function TCppObjectBlock.RestartLoad(Stream: TStream;Count: integer;const TimeShift:double):boolean;
begin
  Result:=inherited RestartLoad(Stream,Count,TimeShift);
  Stream.Read(m_nextTime, SizeOf(double));
  m_nextTime := m_nextTime - TimeShift;
end;

procedure TCppObjectBlock.EditFunc;
var
  count: Integer;
begin
  //SetCondPortCount(VisualObject, count,  pmInput,  PORT_TYPE, sdLeft,  'inport');
end;

end.


