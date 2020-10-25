﻿
 //**************************************************************************//
 // Данный исходный код является составной частью системы МВТУ-4             //
 // Программист:        Никишин Е.В.                                         //
 //**************************************************************************//


library CppObject_lib;

  //**************************************************************************//
  //              Библиотека блока Элкус "ECE-0206-1C"                        //
  //     Автор: Никишин Е.В., октябрь 2020 г.                                 //
  //**************************************************************************//

uses
  SimpleShareMem,
  Classes,
  Info in 'Info.pas',
  ece0206_texts in 'ece0206_texts.pas',
  Blocks in 'Blocks.pas',
  ECE0206Library in 'ECE0206Library.pas',
  URxTxThread in 'URxTxThread.pas',
  URoutineData in 'URoutineData.pas';

{$R *.res}

  //Эта функция возвращает адрес структуры DllInfo
function  GetEntry:Pointer;
begin
  Result:=@DllInfo;
end;

exports
  GetEntry name 'GetEntry',         //Функция получения адреса структуры DllInfo
  CreateObject name 'CreateObject'; //Функция создания объекта

begin
end.
