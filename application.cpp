//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "application.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	com = CreateFile("COM1",
					GENERIC_WRITE|GENERIC_READ,
					0,
					NULL,
					OPEN_EXISTING,
					FILE_FLAG_NO_BUFFERING, //FILE_FLAG_OVERLAPPED,
					NULL);

	if(com == INVALID_HANDLE_VALUE)
	{
		ButtonSend->Enabled = false;
		ButtonReceive->Enabled = false;
	}
	else
	{
		DCB serie;
		// configuration de l’objet serbe
		GetCommState(com, &serie);
		serie.BaudRate = 9600;
		serie.ByteSize = 8;
		serie.Parity = NOPARITY;
		serie.StopBits = ONESTOPBIT;
		SetCommState(com, &serie);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSendExit(TObject *Sender)
{
	CloseHandle(com);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{
	char * test = new char[Edit1->Text.Length()];
	wcstombs(test, Edit1->Text.w_str(), Edit1->Text.Length() + 1);
	unsigned long nbBytesSend;
	WriteFile(com, test, strlen(test) + 1, &nbBytesSend, NULL);
	delete test;
	Edit1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonReceiveClick(TObject *Sender)
{
	char c = 0x00;
	unsigned long nbBytesRecv;

	if(ReadFile(com, &c, 1, &nbBytesRecv, NULL) != 0)
	{
		//received.push_back(c);
		Memo1->Lines->Add(c);
	}
	else
	{
		unsigned long errorCode = GetLastError();
		MessageBox(NULL, "Fail", "Fail", 0);
	}
}
//---------------------------------------------------------------------------
