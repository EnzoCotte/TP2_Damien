//---------------------------------------------------------------------------
#ifndef applicationH
#define applicationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *ButtonSend;
	TButton *ButtonReceive;
	TMemo *Memo1;
	TEdit *Edit1;
	void __fastcall ButtonSendExit(TObject *Sender);
	void __fastcall ButtonSendClick(TObject *Sender);
	void __fastcall ButtonReceiveClick(TObject *Sender);
private:	// Déclarations utilisateur
	HANDLE com;
	//OVERLAPPED over;
	std::vector<char> received;
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
