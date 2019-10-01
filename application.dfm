object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonSend: TButton
    Left = 32
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Envoyer'
    TabOrder = 0
    OnClick = ButtonSendClick
    OnExit = ButtonSendExit
  end
  object ButtonReceive: TButton
    Left = 128
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Recevoir'
    TabOrder = 1
    OnClick = ButtonReceiveClick
  end
  object Memo1: TMemo
    Left = 32
    Top = 99
    Width = 585
    Height = 22
    TabOrder = 2
  end
  object Edit1: TEdit
    Left = 32
    Top = 72
    Width = 585
    Height = 21
    TabOrder = 3
    Text = 'Edit1'
  end
end
