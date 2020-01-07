#pragma once
#include <Windows.h>
#include "ASMExterns.hpp"
#include "Packets.hpp"

extern BOOL IsLoggingSendPackets;

namespace BotOfExile {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;

	/// <summary>
	/// Summary for PacketControls
	/// </summary>
	public ref class PacketControls : public System::Windows::Forms::Form
	{
	public:

		

		PacketControls(void)
		{
			IsLoggingSendPackets = FALSE;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PacketControls()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox_LogSendPackets;
	protected:
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::ListView^  listView_PacketRules;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketRules;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketRulesData;
	private: System::Windows::Forms::TextBox^  textBox_PacketRule1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button_ModifyPacket;
	private: System::Windows::Forms::Button^  button_IgnorePacket;
	private: System::Windows::Forms::Button^  button_BlockPacket;
	private: System::Windows::Forms::TextBox^  textBox_PacketRule2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox_SendPacketInput;
	private: System::Windows::Forms::Button^  button_SendPacket;
	private: System::Windows::Forms::TextBox^  textBox_SpamPacket;
	private: System::Windows::Forms::CheckBox^  checkBox_SpamPacket;
	private: System::Windows::Forms::TextBox^  textBox_SpamPacketDelay;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button_RecvPacket;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::TextBox^  textBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PacketControls::typeid));
			this->checkBox_LogSendPackets = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->listView_PacketRules = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_PacketRules = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_PacketRulesData = (gcnew System::Windows::Forms::ColumnHeader());
			this->textBox_PacketRule1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_ModifyPacket = (gcnew System::Windows::Forms::Button());
			this->button_IgnorePacket = (gcnew System::Windows::Forms::Button());
			this->button_BlockPacket = (gcnew System::Windows::Forms::Button());
			this->textBox_PacketRule2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_SendPacketInput = (gcnew System::Windows::Forms::TextBox());
			this->button_SendPacket = (gcnew System::Windows::Forms::Button());
			this->textBox_SpamPacket = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_SpamPacket = (gcnew System::Windows::Forms::CheckBox());
			this->textBox_SpamPacketDelay = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button_RecvPacket = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox_LogSendPackets
			// 
			this->checkBox_LogSendPackets->AutoSize = true;
			this->checkBox_LogSendPackets->Location = System::Drawing::Point(6, 21);
			this->checkBox_LogSendPackets->Name = L"checkBox_LogSendPackets";
			this->checkBox_LogSendPackets->Size = System::Drawing::Size(94, 17);
			this->checkBox_LogSendPackets->TabIndex = 0;
			this->checkBox_LogSendPackets->Text = L"Log Outbound";
			this->checkBox_LogSendPackets->UseVisualStyleBackColor = true;
			this->checkBox_LogSendPackets->CheckedChanged += gcnew System::EventHandler(this, &PacketControls::checkBox_LogSendPackets_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 43);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(86, 17);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Log Inbound";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// listView_PacketRules
			// 
			this->listView_PacketRules->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader_PacketRules,
					this->columnHeader_PacketRulesData
			});
			this->listView_PacketRules->FullRowSelect = true;
			this->listView_PacketRules->GridLines = true;
			this->listView_PacketRules->Location = System::Drawing::Point(101, 15);
			this->listView_PacketRules->Name = L"listView_PacketRules";
			this->listView_PacketRules->Size = System::Drawing::Size(164, 142);
			this->listView_PacketRules->TabIndex = 9;
			this->listView_PacketRules->UseCompatibleStateImageBehavior = false;
			this->listView_PacketRules->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_PacketRules
			// 
			this->columnHeader_PacketRules->Text = L"Rule";
			this->columnHeader_PacketRules->Width = 66;
			// 
			// columnHeader_PacketRulesData
			// 
			this->columnHeader_PacketRulesData->Text = L"Packet/Opcode";
			this->columnHeader_PacketRulesData->Width = 148;
			// 
			// textBox_PacketRule1
			// 
			this->textBox_PacketRule1->Location = System::Drawing::Point(101, 164);
			this->textBox_PacketRule1->Name = L"textBox_PacketRule1";
			this->textBox_PacketRule1->Size = System::Drawing::Size(166, 20);
			this->textBox_PacketRule1->TabIndex = 10;
			this->textBox_PacketRule1->Text = L"Pattern (\?\? = wildcard)";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_ModifyPacket);
			this->groupBox1->Controls->Add(this->button_IgnorePacket);
			this->groupBox1->Controls->Add(this->button_BlockPacket);
			this->groupBox1->Controls->Add(this->textBox_PacketRule2);
			this->groupBox1->Controls->Add(this->checkBox_LogSendPackets);
			this->groupBox1->Controls->Add(this->textBox_PacketRule1);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->listView_PacketRules);
			this->groupBox1->Location = System::Drawing::Point(8, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(273, 240);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Log Tools";
			// 
			// button_ModifyPacket
			// 
			this->button_ModifyPacket->Location = System::Drawing::Point(212, 214);
			this->button_ModifyPacket->Name = L"button_ModifyPacket";
			this->button_ModifyPacket->Size = System::Drawing::Size(57, 20);
			this->button_ModifyPacket->TabIndex = 14;
			this->button_ModifyPacket->Text = L"Modify";
			this->button_ModifyPacket->UseVisualStyleBackColor = true;
			// 
			// button_IgnorePacket
			// 
			this->button_IgnorePacket->Location = System::Drawing::Point(151, 213);
			this->button_IgnorePacket->Name = L"button_IgnorePacket";
			this->button_IgnorePacket->Size = System::Drawing::Size(55, 20);
			this->button_IgnorePacket->TabIndex = 13;
			this->button_IgnorePacket->Text = L"Ignore";
			this->button_IgnorePacket->UseVisualStyleBackColor = true;
			// 
			// button_BlockPacket
			// 
			this->button_BlockPacket->Location = System::Drawing::Point(101, 213);
			this->button_BlockPacket->Name = L"button_BlockPacket";
			this->button_BlockPacket->Size = System::Drawing::Size(44, 20);
			this->button_BlockPacket->TabIndex = 12;
			this->button_BlockPacket->Text = L"Block";
			this->button_BlockPacket->UseVisualStyleBackColor = true;
			// 
			// textBox_PacketRule2
			// 
			this->textBox_PacketRule2->Location = System::Drawing::Point(101, 187);
			this->textBox_PacketRule2->Name = L"textBox_PacketRule2";
			this->textBox_PacketRule2->Size = System::Drawing::Size(166, 20);
			this->textBox_PacketRule2->TabIndex = 11;
			this->textBox_PacketRule2->Text = L"Replacement (Modify)";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox_SendPacketInput);
			this->groupBox2->Controls->Add(this->button_SendPacket);
			this->groupBox2->Controls->Add(this->textBox_SpamPacket);
			this->groupBox2->Controls->Add(this->checkBox_SpamPacket);
			this->groupBox2->Controls->Add(this->textBox_SpamPacketDelay);
			this->groupBox2->Location = System::Drawing::Point(288, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(267, 121);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Send Tools";
			// 
			// textBox_SendPacketInput
			// 
			this->textBox_SendPacketInput->Location = System::Drawing::Point(6, 68);
			this->textBox_SendPacketInput->Name = L"textBox_SendPacketInput";
			this->textBox_SendPacketInput->Size = System::Drawing::Size(255, 20);
			this->textBox_SendPacketInput->TabIndex = 17;
			this->textBox_SendPacketInput->Text = L"Packet to Send...";
			// 
			// button_SendPacket
			// 
			this->button_SendPacket->Location = System::Drawing::Point(6, 94);
			this->button_SendPacket->Name = L"button_SendPacket";
			this->button_SendPacket->Size = System::Drawing::Size(255, 23);
			this->button_SendPacket->TabIndex = 16;
			this->button_SendPacket->Text = L"Send Outbound";
			this->button_SendPacket->UseVisualStyleBackColor = true;
			this->button_SendPacket->Click += gcnew System::EventHandler(this, &PacketControls::button_SendPacket_Click);
			// 
			// textBox_SpamPacket
			// 
			this->textBox_SpamPacket->Location = System::Drawing::Point(6, 44);
			this->textBox_SpamPacket->Name = L"textBox_SpamPacket";
			this->textBox_SpamPacket->Size = System::Drawing::Size(255, 20);
			this->textBox_SpamPacket->TabIndex = 15;
			this->textBox_SpamPacket->Text = L"Packet to Spam...";
			// 
			// checkBox_SpamPacket
			// 
			this->checkBox_SpamPacket->AutoSize = true;
			this->checkBox_SpamPacket->Location = System::Drawing::Point(112, 20);
			this->checkBox_SpamPacket->Name = L"checkBox_SpamPacket";
			this->checkBox_SpamPacket->Size = System::Drawing::Size(53, 17);
			this->checkBox_SpamPacket->TabIndex = 14;
			this->checkBox_SpamPacket->Text = L"Spam";
			this->checkBox_SpamPacket->UseVisualStyleBackColor = true;
			// 
			// textBox_SpamPacketDelay
			// 
			this->textBox_SpamPacketDelay->Location = System::Drawing::Point(6, 18);
			this->textBox_SpamPacketDelay->Name = L"textBox_SpamPacketDelay";
			this->textBox_SpamPacketDelay->Size = System::Drawing::Size(100, 20);
			this->textBox_SpamPacketDelay->TabIndex = 13;
			this->textBox_SpamPacketDelay->Text = L"Delay (milliseconds)";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button_RecvPacket);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->checkBox2);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Location = System::Drawing::Point(288, 136);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(267, 116);
			this->groupBox3->TabIndex = 13;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Recv Tools";
			// 
			// button_RecvPacket
			// 
			this->button_RecvPacket->Location = System::Drawing::Point(6, 88);
			this->button_RecvPacket->Name = L"button_RecvPacket";
			this->button_RecvPacket->Size = System::Drawing::Size(255, 23);
			this->button_RecvPacket->TabIndex = 19;
			this->button_RecvPacket->Text = L"Inject Recv";
			this->button_RecvPacket->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(6, 65);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(255, 20);
			this->textBox3->TabIndex = 18;
			this->textBox3->Text = L"Packet to Recv...";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(6, 40);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(255, 20);
			this->textBox2->TabIndex = 16;
			this->textBox2->Text = L"Packet to Spam...";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(112, 19);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(82, 17);
			this->checkBox2->TabIndex = 15;
			this->checkBox2->Text = L"Spam Recv";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 14;
			this->textBox1->Text = L"Delay (milliseconds)";
			// 
			// PacketControls
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(564, 256);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PacketControls";
			this->Text = L"Packet Controls";
			this->Load += gcnew System::EventHandler(this, &PacketControls::PacketControls_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}  //01 9F 00 00 00 05 00 00 00 04 00 00 00 06 00 00 00 07 00 00 00 09 00 00 00 0C 
#pragma endregion
	private: System::Void PacketControls_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void checkBox_LogSendPackets_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_LogSendPackets->Checked)
	{
		IsLoggingSendPackets = TRUE;
	}
	else
	{
		IsLoggingSendPackets = FALSE;
	}
}
private: System::Void button_SendPacket_Click(System::Object^  sender, System::EventArgs^  e) {

	UINT64 SendClass = GetSendClass();

	String^ Pocket = gcnew String(this->textBox_SendPacketInput->Text);
	char* string_packet = (char*)(void*)Marshal::StringToHGlobalAnsi(Pocket);
	BYTE* Packet = convertStringToPacketFormat(string_packet);
	int length = getPacketLength(string_packet);
	SendPacket(SendClass, Packet, length);
	delete[] Packet;
}
};
}
