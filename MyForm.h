#pragma once
#include "PacketControls.h"
#include "BotBase.hpp"
#include "ASMExterns.hpp"
#include "Hook.hpp"
#include "Hacks.hpp"
#include "Life.hpp"
#include "Player.hpp"
#include "Positioned.hpp"
#include "HideDLL.hpp"
#include <queue>

extern int SubwindowMain();
extern BOOL IsLoggingComponents;
extern BOOL IsLoggingSendPackets;

BotType BotBase::Type = 1;
BotBase *BotBase::BotInstance = 0;

extern std::queue<PacketWriter*> SendPacketQueue;
extern HMODULE hDLLModule;

HANDLE ReduceRAMThread = NULL;

namespace BotOfExile {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Thread^ SendPacketsLogThread;
		Thread^ LogInfoThread;
	private: System::Windows::Forms::ComboBox^  comboBox_FlaskPiano;
	
	private: System::Windows::Forms::CheckBox^  checkBox_FlaskPianoHotkey;
	private: System::Windows::Forms::CheckBox^  checkBox_LogMonsterInfo;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_CharSize;
	private: System::Windows::Forms::Button^  button_SetCharSize;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown_HideoutID;
	private: System::Windows::Forms::Button^  button_SwapHideout;
	private: System::Windows::Forms::Label^  label_CurrentArea;
	private: System::Windows::Forms::CheckBox^  checkBox_LogCharacterInfo;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_AreaToBot;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  radioButton_IsRanged;
	private: System::Windows::Forms::TextBox^  textBox_MainAttack;
	private: System::Windows::Forms::Label^  label_Int;
	private: System::Windows::Forms::Label^  label_Dex;

	private: System::Windows::Forms::Label^  label_Str;
	private: System::Windows::Forms::Label^  label_Exp;
	private: System::Windows::Forms::Label^  label_Lvl;
	private: System::Windows::Forms::Button^  button_SetAttackSkill;
	private: System::Windows::Forms::RadioButton^  radioButton_IsMelee;
			 PacketControls^ PacketWindow;
	
	public:
			 MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_PacketLog;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  copySelectedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearListToolStripMenuItem;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage_Hacks;
	private: System::Windows::Forms::TabPage^  tabPage_Packets;
	private: System::Windows::Forms::GroupBox^  groupBox_Exploits;
	private: System::Windows::Forms::GroupBox^  groupBox_Hotkeys;
	private: System::Windows::Forms::GroupBox^  groupBox_UtilityHacks;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_CPUReducer;
	private: System::Windows::Forms::CheckBox^  checkBox_RAMReducer;
	private: System::Windows::Forms::CheckBox^  checkBox_CPUReducer;
	private: System::Windows::Forms::GroupBox^  groupBox_Maphacks;
	private: System::Windows::Forms::CheckBox^  checkBox_LightsExpanse;



	private: System::Windows::Forms::RadioButton^  radioButton_LogComponents;
	private: System::Windows::Forms::CheckBox^  checkBox_ZoomHack;
	private: System::Windows::Forms::CheckBox^  checkBox_LogEntitySpawn;
	private: System::Windows::Forms::CheckBox^  checkBox_RevealMap;
	private: System::Windows::Forms::Button^  button_OpenPacketGUI;
	private: System::Windows::Forms::ListView^  listView_SendPacketLog;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketLength;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketOpcode;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketData;
	private: System::Windows::Forms::TabPage^  tabPage_LUA;
	private: System::Windows::Forms::Button^  button_DownloadLUA;
	private: System::Windows::Forms::Button^  button_LoadLUAScript;
	private: System::Windows::Forms::Button^  button_SaveScript;
	private: System::Windows::Forms::Button^  button_EndScript;
	private: System::Windows::Forms::Button^  button_RunScript;
	private: System::Windows::Forms::TextBox^  textBox_ScriptText;
	private: System::Windows::Forms::TabPage^  tabPage_Bots;
	private: System::Windows::Forms::GroupBox^  groupBox_TimedShutdown;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox_TimedProcessClose;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker_Shutdown;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TextBox^  textBox_ExtraAttacksSkillName;
	private: System::Windows::Forms::ListView^  listView_ExtraAttacks;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::ColumnHeader^  columnHeader9;
	private: System::Windows::Forms::ColumnHeader^  columnHeader10;
	private: System::Windows::Forms::TextBox^  textBox_ExtraAttacksDelay;
	private: System::Windows::Forms::TextBox^  textBox_ExtraAttackSkillID;
	private: System::Windows::Forms::Button^  button_AddAttackSkill;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  textBox_TimedFlask4;
	private: System::Windows::Forms::TextBox^  textBox_TimerFlask4;
	private: System::Windows::Forms::CheckBox^  checkBox_TimedFlask4;
	private: System::Windows::Forms::ListView^  listView_CurrentFlasks;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::TextBox^  textBox_TimerFlask3;
	private: System::Windows::Forms::TextBox^  textBox_TimerFlask2;
	private: System::Windows::Forms::TextBox^  textBox_TimedFlask3;
	private: System::Windows::Forms::TextBox^  textBox_TimedFlask2;
	private: System::Windows::Forms::TextBox^  textBox_TimedFlask1;
	private: System::Windows::Forms::TextBox^  textBox_TimerFlask1;
	private: System::Windows::Forms::CheckBox^  checkBox_TimedFlask3;
	private: System::Windows::Forms::CheckBox^  checkBox_TimedFlask2;
	private: System::Windows::Forms::CheckBox^  checkBox_TimedFlask1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_AutoMP;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_AutoHP;
	private: System::Windows::Forms::CheckBox^  checkBox_AutoHP;
	private: System::Windows::Forms::TextBox^  textBox_BeltSlotMP;
	private: System::Windows::Forms::TextBox^  textBox_BeltSlotHP;
	private: System::Windows::Forms::CheckBox^  checkBox_AutoMP;
	private: System::Windows::Forms::GroupBox^  groupBox_Reviver;
	private: System::Windows::Forms::CheckBox^  checkBox_CastBuffsOnRevive;
	private: System::Windows::Forms::RadioButton^  radioButton_ReviveWaypoint;
	private: System::Windows::Forms::RadioButton^  radioButton_ReviveTown;
	private: System::Windows::Forms::CheckBox^  checkBox_ReviveOnDeath;
	private: System::Windows::Forms::GroupBox^  groupBox_BotProfile;
	private: System::Windows::Forms::Button^  button_SaveProfile;
	private: System::Windows::Forms::Button^  button_LoadProfile;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::CheckBox^  checkBox_EnableBot;
	private: System::Windows::Forms::ComboBox^  comboBox_BotType;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Label^  label_Y;
	private: System::Windows::Forms::Label^  label_X;
private: System::Windows::Forms::CheckBox^  checkBox_UseDynamite;
private: System::Windows::Forms::ComboBox^  comboBox_UseDynamite;
private: System::Windows::Forms::ComboBox^  comboBox_FlareHotkey;
private: System::Windows::Forms::CheckBox^  checkBox_UseFlare;
private: System::Windows::Forms::CheckBox^  checkBox_Hideout;
private: System::Windows::Forms::ComboBox^  comboBox_HideoutKey;
	protected:



	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_Hacks = (gcnew System::Windows::Forms::TabPage());
			this->groupBox_Exploits = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_HideoutID = (gcnew System::Windows::Forms::NumericUpDown());
			this->button_SwapHideout = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox_Hotkeys = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox_FlaskPiano = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox_FlaskPianoHotkey = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Hideout = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox_HideoutKey = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox_UseDynamite = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox_UseDynamite = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_FlareHotkey = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox_UseFlare = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_UtilityHacks = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_CPUReducer = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_RAMReducer = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_CPUReducer = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_Maphacks = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_CharSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->button_SetCharSize = (gcnew System::Windows::Forms::Button());
			this->checkBox_LogMonsterInfo = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_LightsExpanse = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton_LogComponents = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox_ZoomHack = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_LogEntitySpawn = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_RevealMap = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage_Packets = (gcnew System::Windows::Forms::TabPage());
			this->button_OpenPacketGUI = (gcnew System::Windows::Forms::Button());
			this->listView_SendPacketLog = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_PacketLength = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_PacketOpcode = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_PacketData = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_PacketLog = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copySelectedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage_LUA = (gcnew System::Windows::Forms::TabPage());
			this->button_DownloadLUA = (gcnew System::Windows::Forms::Button());
			this->button_LoadLUAScript = (gcnew System::Windows::Forms::Button());
			this->button_SaveScript = (gcnew System::Windows::Forms::Button());
			this->button_EndScript = (gcnew System::Windows::Forms::Button());
			this->button_RunScript = (gcnew System::Windows::Forms::Button());
			this->textBox_ScriptText = (gcnew System::Windows::Forms::TextBox());
			this->tabPage_Bots = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_SetAttackSkill = (gcnew System::Windows::Forms::Button());
			this->radioButton_IsMelee = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_IsRanged = (gcnew System::Windows::Forms::RadioButton());
			this->textBox_MainAttack = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_Int = (gcnew System::Windows::Forms::Label());
			this->label_Dex = (gcnew System::Windows::Forms::Label());
			this->label_Str = (gcnew System::Windows::Forms::Label());
			this->label_Exp = (gcnew System::Windows::Forms::Label());
			this->label_Lvl = (gcnew System::Windows::Forms::Label());
			this->checkBox_LogCharacterInfo = (gcnew System::Windows::Forms::CheckBox());
			this->label_CurrentArea = (gcnew System::Windows::Forms::Label());
			this->label_Y = (gcnew System::Windows::Forms::Label());
			this->label_X = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown_AreaToBot = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_EnableBot = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox_BotType = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_ExtraAttacksSkillName = (gcnew System::Windows::Forms::TextBox());
			this->listView_ExtraAttacks = (gcnew System::Windows::Forms::ListView());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->textBox_ExtraAttacksDelay = (gcnew System::Windows::Forms::TextBox());
			this->textBox_ExtraAttackSkillID = (gcnew System::Windows::Forms::TextBox());
			this->button_AddAttackSkill = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_TimedFlask4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_TimerFlask4 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_TimedFlask4 = (gcnew System::Windows::Forms::CheckBox());
			this->listView_CurrentFlasks = (gcnew System::Windows::Forms::ListView());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->textBox_TimerFlask3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_TimerFlask2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_TimedFlask3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_TimedFlask2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_TimedFlask1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_TimerFlask1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_TimedFlask3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_TimedFlask2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_TimedFlask1 = (gcnew System::Windows::Forms::CheckBox());
			this->numericUpDown_AutoMP = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_AutoHP = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_AutoHP = (gcnew System::Windows::Forms::CheckBox());
			this->textBox_BeltSlotMP = (gcnew System::Windows::Forms::TextBox());
			this->textBox_BeltSlotHP = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_AutoMP = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_Reviver = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_CastBuffsOnRevive = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton_ReviveWaypoint = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_ReviveTown = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox_ReviveOnDeath = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_BotProfile = (gcnew System::Windows::Forms::GroupBox());
			this->button_SaveProfile = (gcnew System::Windows::Forms::Button());
			this->button_LoadProfile = (gcnew System::Windows::Forms::Button());
			this->groupBox_TimedShutdown = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_TimedProcessClose = (gcnew System::Windows::Forms::CheckBox());
			this->dateTimePicker_Shutdown = (gcnew System::Windows::Forms::DateTimePicker());
			this->tabControl1->SuspendLayout();
			this->tabPage_Hacks->SuspendLayout();
			this->groupBox_Exploits->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_HideoutID))->BeginInit();
			this->groupBox_Hotkeys->SuspendLayout();
			this->groupBox_UtilityHacks->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CPUReducer))->BeginInit();
			this->groupBox_Maphacks->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CharSize))->BeginInit();
			this->tabPage_Packets->SuspendLayout();
			this->contextMenuStrip_PacketLog->SuspendLayout();
			this->tabPage_LUA->SuspendLayout();
			this->tabPage_Bots->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AreaToBot))->BeginInit();
			this->groupBox6->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AutoMP))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AutoHP))->BeginInit();
			this->groupBox_Reviver->SuspendLayout();
			this->groupBox_BotProfile->SuspendLayout();
			this->groupBox_TimedShutdown->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage_Hacks);
			this->tabControl1->Controls->Add(this->tabPage_Packets);
			this->tabControl1->Controls->Add(this->tabPage_LUA);
			this->tabControl1->Controls->Add(this->tabPage_Bots);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(566, 413);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage_Hacks
			// 
			this->tabPage_Hacks->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tabPage_Hacks->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->tabPage_Hacks->Controls->Add(this->groupBox_Exploits);
			this->tabPage_Hacks->Controls->Add(this->groupBox_Hotkeys);
			this->tabPage_Hacks->Controls->Add(this->groupBox_UtilityHacks);
			this->tabPage_Hacks->Controls->Add(this->groupBox_Maphacks);
			this->tabPage_Hacks->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tabPage_Hacks->Location = System::Drawing::Point(4, 23);
			this->tabPage_Hacks->Name = L"tabPage_Hacks";
			this->tabPage_Hacks->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Hacks->Size = System::Drawing::Size(558, 386);
			this->tabPage_Hacks->TabIndex = 0;
			this->tabPage_Hacks->Text = L"Hacks";
			// 
			// groupBox_Exploits
			// 
			this->groupBox_Exploits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->groupBox_Exploits->Controls->Add(this->numericUpDown_HideoutID);
			this->groupBox_Exploits->Controls->Add(this->button_SwapHideout);
			this->groupBox_Exploits->Controls->Add(this->button1);
			this->groupBox_Exploits->Location = System::Drawing::Point(175, 86);
			this->groupBox_Exploits->Name = L"groupBox_Exploits";
			this->groupBox_Exploits->Size = System::Drawing::Size(169, 293);
			this->groupBox_Exploits->TabIndex = 3;
			this->groupBox_Exploits->TabStop = false;
			this->groupBox_Exploits->Text = L"Network Exploit-Related";
			// 
			// numericUpDown_HideoutID
			// 
			this->numericUpDown_HideoutID->Location = System::Drawing::Point(93, 24);
			this->numericUpDown_HideoutID->Name = L"numericUpDown_HideoutID";
			this->numericUpDown_HideoutID->Size = System::Drawing::Size(67, 21);
			this->numericUpDown_HideoutID->TabIndex = 1;
			this->numericUpDown_HideoutID->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			// 
			// button_SwapHideout
			// 
			this->button_SwapHideout->Location = System::Drawing::Point(6, 23);
			this->button_SwapHideout->Name = L"button_SwapHideout";
			this->button_SwapHideout->Size = System::Drawing::Size(81, 23);
			this->button_SwapHideout->TabIndex = 0;
			this->button_SwapHideout->Text = L"Go Hideout";
			this->button_SwapHideout->UseVisualStyleBackColor = true;
			this->button_SwapHideout->Click += gcnew System::EventHandler(this, &MyForm::button_SwapHideout_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 264);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Testing Funcs.";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox_Hotkeys
			// 
			this->groupBox_Hotkeys->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_Hotkeys->Controls->Add(this->comboBox_FlaskPiano);
			this->groupBox_Hotkeys->Controls->Add(this->checkBox_FlaskPianoHotkey);
			this->groupBox_Hotkeys->Controls->Add(this->checkBox_Hideout);
			this->groupBox_Hotkeys->Controls->Add(this->comboBox_HideoutKey);
			this->groupBox_Hotkeys->Controls->Add(this->checkBox_UseDynamite);
			this->groupBox_Hotkeys->Controls->Add(this->comboBox_UseDynamite);
			this->groupBox_Hotkeys->Controls->Add(this->comboBox_FlareHotkey);
			this->groupBox_Hotkeys->Controls->Add(this->checkBox_UseFlare);
			this->groupBox_Hotkeys->Location = System::Drawing::Point(350, 7);
			this->groupBox_Hotkeys->Name = L"groupBox_Hotkeys";
			this->groupBox_Hotkeys->Size = System::Drawing::Size(202, 371);
			this->groupBox_Hotkeys->TabIndex = 2;
			this->groupBox_Hotkeys->TabStop = false;
			this->groupBox_Hotkeys->Text = L"Hotkey-Related";
			// 
			// comboBox_FlaskPiano
			// 
			this->comboBox_FlaskPiano->FormattingEnabled = true;
			this->comboBox_FlaskPiano->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"F2", L"F3", L"F4", L"F5", L"F6", L"F7",
					L"F8", L"F9"
			});
			this->comboBox_FlaskPiano->Location = System::Drawing::Point(118, 103);
			this->comboBox_FlaskPiano->Name = L"comboBox_FlaskPiano";
			this->comboBox_FlaskPiano->Size = System::Drawing::Size(78, 22);
			this->comboBox_FlaskPiano->TabIndex = 8;
			this->comboBox_FlaskPiano->Text = L"~";
			// 
			// checkBox_FlaskPianoHotkey
			// 
			this->checkBox_FlaskPianoHotkey->AutoSize = true;
			this->checkBox_FlaskPianoHotkey->Location = System::Drawing::Point(6, 106);
			this->checkBox_FlaskPianoHotkey->Name = L"checkBox_FlaskPianoHotkey";
			this->checkBox_FlaskPianoHotkey->Size = System::Drawing::Size(84, 18);
			this->checkBox_FlaskPianoHotkey->TabIndex = 7;
			this->checkBox_FlaskPianoHotkey->Text = L"Flask Piano";
			this->checkBox_FlaskPianoHotkey->UseVisualStyleBackColor = true;
			// 
			// checkBox_Hideout
			// 
			this->checkBox_Hideout->AutoSize = true;
			this->checkBox_Hideout->Location = System::Drawing::Point(6, 78);
			this->checkBox_Hideout->Name = L"checkBox_Hideout";
			this->checkBox_Hideout->Size = System::Drawing::Size(68, 18);
			this->checkBox_Hideout->TabIndex = 6;
			this->checkBox_Hideout->Text = L"Hideout";
			this->checkBox_Hideout->UseVisualStyleBackColor = true;
			// 
			// comboBox_HideoutKey
			// 
			this->comboBox_HideoutKey->FormattingEnabled = true;
			this->comboBox_HideoutKey->Location = System::Drawing::Point(118, 75);
			this->comboBox_HideoutKey->Name = L"comboBox_HideoutKey";
			this->comboBox_HideoutKey->Size = System::Drawing::Size(78, 22);
			this->comboBox_HideoutKey->TabIndex = 5;
			this->comboBox_HideoutKey->Text = L"F4";
			// 
			// checkBox_UseDynamite
			// 
			this->checkBox_UseDynamite->AutoSize = true;
			this->checkBox_UseDynamite->Location = System::Drawing::Point(6, 50);
			this->checkBox_UseDynamite->Name = L"checkBox_UseDynamite";
			this->checkBox_UseDynamite->Size = System::Drawing::Size(96, 18);
			this->checkBox_UseDynamite->TabIndex = 4;
			this->checkBox_UseDynamite->Text = L"Use Dynamite";
			this->checkBox_UseDynamite->UseVisualStyleBackColor = true;
			this->checkBox_UseDynamite->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_UseDynamite_CheckedChanged);
			// 
			// comboBox_UseDynamite
			// 
			this->comboBox_UseDynamite->FormattingEnabled = true;
			this->comboBox_UseDynamite->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"F2", L"F3", L"F4", L"F5", L"F6", L"F7",
					L"F8", L"F9"
			});
			this->comboBox_UseDynamite->Location = System::Drawing::Point(118, 47);
			this->comboBox_UseDynamite->Name = L"comboBox_UseDynamite";
			this->comboBox_UseDynamite->Size = System::Drawing::Size(78, 22);
			this->comboBox_UseDynamite->TabIndex = 3;
			this->comboBox_UseDynamite->Text = L"F3";
			// 
			// comboBox_FlareHotkey
			// 
			this->comboBox_FlareHotkey->FormattingEnabled = true;
			this->comboBox_FlareHotkey->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"F2", L"F3", L"F4", L"F5", L"F6", L"F7",
					L"F8", L"F9"
			});
			this->comboBox_FlareHotkey->Location = System::Drawing::Point(118, 19);
			this->comboBox_FlareHotkey->Name = L"comboBox_FlareHotkey";
			this->comboBox_FlareHotkey->Size = System::Drawing::Size(78, 22);
			this->comboBox_FlareHotkey->TabIndex = 2;
			this->comboBox_FlareHotkey->Text = L"F2";
			// 
			// checkBox_UseFlare
			// 
			this->checkBox_UseFlare->AutoSize = true;
			this->checkBox_UseFlare->Location = System::Drawing::Point(6, 21);
			this->checkBox_UseFlare->Name = L"checkBox_UseFlare";
			this->checkBox_UseFlare->Size = System::Drawing::Size(73, 18);
			this->checkBox_UseFlare->TabIndex = 1;
			this->checkBox_UseFlare->Text = L"Use Flare";
			this->checkBox_UseFlare->UseVisualStyleBackColor = true;
			this->checkBox_UseFlare->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_UseFlare_CheckedChanged);
			// 
			// groupBox_UtilityHacks
			// 
			this->groupBox_UtilityHacks->Controls->Add(this->numericUpDown_CPUReducer);
			this->groupBox_UtilityHacks->Controls->Add(this->checkBox_RAMReducer);
			this->groupBox_UtilityHacks->Controls->Add(this->checkBox_CPUReducer);
			this->groupBox_UtilityHacks->Location = System::Drawing::Point(175, 7);
			this->groupBox_UtilityHacks->Name = L"groupBox_UtilityHacks";
			this->groupBox_UtilityHacks->Size = System::Drawing::Size(169, 73);
			this->groupBox_UtilityHacks->TabIndex = 1;
			this->groupBox_UtilityHacks->TabStop = false;
			this->groupBox_UtilityHacks->Text = L"Utility-Related";
			// 
			// numericUpDown_CPUReducer
			// 
			this->numericUpDown_CPUReducer->Location = System::Drawing::Point(102, 18);
			this->numericUpDown_CPUReducer->Name = L"numericUpDown_CPUReducer";
			this->numericUpDown_CPUReducer->Size = System::Drawing::Size(58, 21);
			this->numericUpDown_CPUReducer->TabIndex = 2;
			// 
			// checkBox_RAMReducer
			// 
			this->checkBox_RAMReducer->AutoSize = true;
			this->checkBox_RAMReducer->Location = System::Drawing::Point(6, 43);
			this->checkBox_RAMReducer->Name = L"checkBox_RAMReducer";
			this->checkBox_RAMReducer->Size = System::Drawing::Size(92, 18);
			this->checkBox_RAMReducer->TabIndex = 1;
			this->checkBox_RAMReducer->Text = L"RAM Cleaner";
			this->checkBox_RAMReducer->UseVisualStyleBackColor = true;
			this->checkBox_RAMReducer->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_RAMReducer_CheckedChanged);
			// 
			// checkBox_CPUReducer
			// 
			this->checkBox_CPUReducer->AutoSize = true;
			this->checkBox_CPUReducer->Location = System::Drawing::Point(6, 20);
			this->checkBox_CPUReducer->Name = L"checkBox_CPUReducer";
			this->checkBox_CPUReducer->Size = System::Drawing::Size(94, 18);
			this->checkBox_CPUReducer->TabIndex = 0;
			this->checkBox_CPUReducer->Text = L"Frame Limiter";
			this->checkBox_CPUReducer->UseVisualStyleBackColor = true;
			// 
			// groupBox_Maphacks
			// 
			this->groupBox_Maphacks->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->groupBox_Maphacks->Controls->Add(this->numericUpDown_CharSize);
			this->groupBox_Maphacks->Controls->Add(this->button_SetCharSize);
			this->groupBox_Maphacks->Controls->Add(this->checkBox_LogMonsterInfo);
			this->groupBox_Maphacks->Controls->Add(this->checkBox_LightsExpanse);
			this->groupBox_Maphacks->Controls->Add(this->radioButton_LogComponents);
			this->groupBox_Maphacks->Controls->Add(this->checkBox_ZoomHack);
			this->groupBox_Maphacks->Controls->Add(this->checkBox_LogEntitySpawn);
			this->groupBox_Maphacks->Controls->Add(this->checkBox_RevealMap);
			this->groupBox_Maphacks->Location = System::Drawing::Point(6, 6);
			this->groupBox_Maphacks->Name = L"groupBox_Maphacks";
			this->groupBox_Maphacks->Size = System::Drawing::Size(163, 373);
			this->groupBox_Maphacks->TabIndex = 0;
			this->groupBox_Maphacks->TabStop = false;
			this->groupBox_Maphacks->Text = L"Map-Related";
			// 
			// numericUpDown_CharSize
			// 
			this->numericUpDown_CharSize->Location = System::Drawing::Point(103, 164);
			this->numericUpDown_CharSize->Name = L"numericUpDown_CharSize";
			this->numericUpDown_CharSize->Size = System::Drawing::Size(54, 21);
			this->numericUpDown_CharSize->TabIndex = 28;
			// 
			// button_SetCharSize
			// 
			this->button_SetCharSize->Location = System::Drawing::Point(6, 163);
			this->button_SetCharSize->Name = L"button_SetCharSize";
			this->button_SetCharSize->Size = System::Drawing::Size(91, 23);
			this->button_SetCharSize->TabIndex = 27;
			this->button_SetCharSize->Text = L"Character Size";
			this->button_SetCharSize->UseVisualStyleBackColor = true;
			this->button_SetCharSize->Click += gcnew System::EventHandler(this, &MyForm::button_SetCharSize_Click);
			// 
			// checkBox_LogMonsterInfo
			// 
			this->checkBox_LogMonsterInfo->AutoSize = true;
			this->checkBox_LogMonsterInfo->Location = System::Drawing::Point(6, 92);
			this->checkBox_LogMonsterInfo->Name = L"checkBox_LogMonsterInfo";
			this->checkBox_LogMonsterInfo->Size = System::Drawing::Size(115, 18);
			this->checkBox_LogMonsterInfo->TabIndex = 26;
			this->checkBox_LogMonsterInfo->Text = L"Log Monster Info";
			this->checkBox_LogMonsterInfo->UseVisualStyleBackColor = true;
			this->checkBox_LogMonsterInfo->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_LogMonsterInfo_CheckedChanged);
			// 
			// checkBox_LightsExpanse
			// 
			this->checkBox_LightsExpanse->AutoSize = true;
			this->checkBox_LightsExpanse->Location = System::Drawing::Point(6, 138);
			this->checkBox_LightsExpanse->Name = L"checkBox_LightsExpanse";
			this->checkBox_LightsExpanse->Size = System::Drawing::Size(114, 18);
			this->checkBox_LightsExpanse->TabIndex = 5;
			this->checkBox_LightsExpanse->Text = L"Lighting Increase";
			this->checkBox_LightsExpanse->UseVisualStyleBackColor = true;
			this->checkBox_LightsExpanse->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_LightsExpanse_CheckedChanged);
			// 
			// radioButton_LogComponents
			// 
			this->radioButton_LogComponents->AutoSize = true;
			this->radioButton_LogComponents->Location = System::Drawing::Point(28, 68);
			this->radioButton_LogComponents->Name = L"radioButton_LogComponents";
			this->radioButton_LogComponents->Size = System::Drawing::Size(113, 18);
			this->radioButton_LogComponents->TabIndex = 4;
			this->radioButton_LogComponents->TabStop = true;
			this->radioButton_LogComponents->Text = L"Log Components";
			this->radioButton_LogComponents->UseVisualStyleBackColor = true;
			this->radioButton_LogComponents->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_LogComponents_CheckedChanged);
			// 
			// checkBox_ZoomHack
			// 
			this->checkBox_ZoomHack->AutoSize = true;
			this->checkBox_ZoomHack->Location = System::Drawing::Point(6, 115);
			this->checkBox_ZoomHack->Name = L"checkBox_ZoomHack";
			this->checkBox_ZoomHack->Size = System::Drawing::Size(147, 18);
			this->checkBox_ZoomHack->TabIndex = 3;
			this->checkBox_ZoomHack->Text = L"Disable Zoom-in Limiter";
			this->checkBox_ZoomHack->UseVisualStyleBackColor = true;
			this->checkBox_ZoomHack->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_ZoomHack_CheckedChanged);
			// 
			// checkBox_LogEntitySpawn
			// 
			this->checkBox_LogEntitySpawn->AutoSize = true;
			this->checkBox_LogEntitySpawn->Checked = true;
			this->checkBox_LogEntitySpawn->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_LogEntitySpawn->Location = System::Drawing::Point(6, 44);
			this->checkBox_LogEntitySpawn->Name = L"checkBox_LogEntitySpawn";
			this->checkBox_LogEntitySpawn->Size = System::Drawing::Size(86, 18);
			this->checkBox_LogEntitySpawn->TabIndex = 1;
			this->checkBox_LogEntitySpawn->Text = L"Log Entities";
			this->checkBox_LogEntitySpawn->UseVisualStyleBackColor = true;
			this->checkBox_LogEntitySpawn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_LogEntitySpawn_CheckedChanged);
			// 
			// checkBox_RevealMap
			// 
			this->checkBox_RevealMap->AutoSize = true;
			this->checkBox_RevealMap->Location = System::Drawing::Point(6, 20);
			this->checkBox_RevealMap->Name = L"checkBox_RevealMap";
			this->checkBox_RevealMap->Size = System::Drawing::Size(85, 18);
			this->checkBox_RevealMap->TabIndex = 0;
			this->checkBox_RevealMap->Text = L"Reveal Map";
			this->checkBox_RevealMap->UseVisualStyleBackColor = true;
			this->checkBox_RevealMap->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_RevealMap_CheckedChanged);
			// 
			// tabPage_Packets
			// 
			this->tabPage_Packets->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tabPage_Packets->Controls->Add(this->button_OpenPacketGUI);
			this->tabPage_Packets->Controls->Add(this->listView_SendPacketLog);
			this->tabPage_Packets->Location = System::Drawing::Point(4, 23);
			this->tabPage_Packets->Name = L"tabPage_Packets";
			this->tabPage_Packets->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Packets->Size = System::Drawing::Size(558, 386);
			this->tabPage_Packets->TabIndex = 1;
			this->tabPage_Packets->Text = L"Packets";
			// 
			// button_OpenPacketGUI
			// 
			this->button_OpenPacketGUI->BackColor = System::Drawing::SystemColors::ControlText;
			this->button_OpenPacketGUI->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button_OpenPacketGUI->ForeColor = System::Drawing::Color::Aqua;
			this->button_OpenPacketGUI->Location = System::Drawing::Point(3, 360);
			this->button_OpenPacketGUI->Name = L"button_OpenPacketGUI";
			this->button_OpenPacketGUI->Size = System::Drawing::Size(552, 23);
			this->button_OpenPacketGUI->TabIndex = 3;
			this->button_OpenPacketGUI->Text = L"Open Packet Controls";
			this->button_OpenPacketGUI->UseVisualStyleBackColor = false;
			this->button_OpenPacketGUI->Click += gcnew System::EventHandler(this, &MyForm::button_OpenPacketGUI_Click);
			// 
			// listView_SendPacketLog
			// 
			this->listView_SendPacketLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView_SendPacketLog->BackColor = System::Drawing::SystemColors::ControlLight;
			this->listView_SendPacketLog->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader_PacketLength,
					this->columnHeader_PacketOpcode, this->columnHeader_PacketData
			});
			this->listView_SendPacketLog->ContextMenuStrip = this->contextMenuStrip_PacketLog;
			this->listView_SendPacketLog->FullRowSelect = true;
			this->listView_SendPacketLog->GridLines = true;
			this->listView_SendPacketLog->Location = System::Drawing::Point(3, 3);
			this->listView_SendPacketLog->Name = L"listView_SendPacketLog";
			this->listView_SendPacketLog->Size = System::Drawing::Size(549, 351);
			this->listView_SendPacketLog->TabIndex = 2;
			this->listView_SendPacketLog->UseCompatibleStateImageBehavior = false;
			this->listView_SendPacketLog->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_PacketLength
			// 
			this->columnHeader_PacketLength->Text = L"Size";
			this->columnHeader_PacketLength->Width = 42;
			// 
			// columnHeader_PacketOpcode
			// 
			this->columnHeader_PacketOpcode->Text = L"Opcode";
			this->columnHeader_PacketOpcode->Width = 54;
			// 
			// columnHeader_PacketData
			// 
			this->columnHeader_PacketData->Text = L"Data";
			this->columnHeader_PacketData->Width = 854;
			// 
			// contextMenuStrip_PacketLog
			// 
			this->contextMenuStrip_PacketLog->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copySelectedToolStripMenuItem,
					this->clearListToolStripMenuItem
			});
			this->contextMenuStrip_PacketLog->Name = L"contextMenuStrip_PacketLog";
			this->contextMenuStrip_PacketLog->Size = System::Drawing::Size(150, 48);
			// 
			// copySelectedToolStripMenuItem
			// 
			this->copySelectedToolStripMenuItem->Name = L"copySelectedToolStripMenuItem";
			this->copySelectedToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->copySelectedToolStripMenuItem->Text = L"Copy Selected";
			this->copySelectedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::copySelectedToolStripMenuItem_Click);
			// 
			// clearListToolStripMenuItem
			// 
			this->clearListToolStripMenuItem->Name = L"clearListToolStripMenuItem";
			this->clearListToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->clearListToolStripMenuItem->Text = L"Clear List";
			this->clearListToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearListToolStripMenuItem_Click);
			// 
			// tabPage_LUA
			// 
			this->tabPage_LUA->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tabPage_LUA->Controls->Add(this->button_DownloadLUA);
			this->tabPage_LUA->Controls->Add(this->button_LoadLUAScript);
			this->tabPage_LUA->Controls->Add(this->button_SaveScript);
			this->tabPage_LUA->Controls->Add(this->button_EndScript);
			this->tabPage_LUA->Controls->Add(this->button_RunScript);
			this->tabPage_LUA->Controls->Add(this->textBox_ScriptText);
			this->tabPage_LUA->Location = System::Drawing::Point(4, 23);
			this->tabPage_LUA->Name = L"tabPage_LUA";
			this->tabPage_LUA->Size = System::Drawing::Size(558, 386);
			this->tabPage_LUA->TabIndex = 2;
			this->tabPage_LUA->Text = L"LUA";
			// 
			// button_DownloadLUA
			// 
			this->button_DownloadLUA->BackColor = System::Drawing::Color::Green;
			this->button_DownloadLUA->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button_DownloadLUA->Location = System::Drawing::Point(0, 274);
			this->button_DownloadLUA->Name = L"button_DownloadLUA";
			this->button_DownloadLUA->Size = System::Drawing::Size(558, 23);
			this->button_DownloadLUA->TabIndex = 8;
			this->button_DownloadLUA->Text = L"Download Script";
			this->button_DownloadLUA->UseVisualStyleBackColor = false;
			// 
			// button_LoadLUAScript
			// 
			this->button_LoadLUAScript->BackColor = System::Drawing::Color::Yellow;
			this->button_LoadLUAScript->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button_LoadLUAScript->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button_LoadLUAScript->Location = System::Drawing::Point(0, 297);
			this->button_LoadLUAScript->Name = L"button_LoadLUAScript";
			this->button_LoadLUAScript->Size = System::Drawing::Size(558, 20);
			this->button_LoadLUAScript->TabIndex = 7;
			this->button_LoadLUAScript->Text = L"Load Script";
			this->button_LoadLUAScript->UseVisualStyleBackColor = false;
			// 
			// button_SaveScript
			// 
			this->button_SaveScript->BackColor = System::Drawing::Color::Blue;
			this->button_SaveScript->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button_SaveScript->Location = System::Drawing::Point(0, 317);
			this->button_SaveScript->Name = L"button_SaveScript";
			this->button_SaveScript->Size = System::Drawing::Size(558, 23);
			this->button_SaveScript->TabIndex = 6;
			this->button_SaveScript->Text = L"Save Script";
			this->button_SaveScript->UseVisualStyleBackColor = false;
			// 
			// button_EndScript
			// 
			this->button_EndScript->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_EndScript->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button_EndScript->Location = System::Drawing::Point(0, 340);
			this->button_EndScript->Name = L"button_EndScript";
			this->button_EndScript->Size = System::Drawing::Size(558, 23);
			this->button_EndScript->TabIndex = 5;
			this->button_EndScript->Text = L"End Script";
			this->button_EndScript->UseVisualStyleBackColor = false;
			// 
			// button_RunScript
			// 
			this->button_RunScript->BackColor = System::Drawing::Color::YellowGreen;
			this->button_RunScript->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button_RunScript->Location = System::Drawing::Point(0, 363);
			this->button_RunScript->Name = L"button_RunScript";
			this->button_RunScript->Size = System::Drawing::Size(558, 23);
			this->button_RunScript->TabIndex = 4;
			this->button_RunScript->Text = L"Run Script";
			this->button_RunScript->UseVisualStyleBackColor = false;
			this->button_RunScript->Click += gcnew System::EventHandler(this, &MyForm::button_RunScript_Click);
			// 
			// textBox_ScriptText
			// 
			this->textBox_ScriptText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_ScriptText->BackColor = System::Drawing::Color::DarkGray;
			this->textBox_ScriptText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_ScriptText->Location = System::Drawing::Point(2, 3);
			this->textBox_ScriptText->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox_ScriptText->Multiline = true;
			this->textBox_ScriptText->Name = L"textBox_ScriptText";
			this->textBox_ScriptText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_ScriptText->Size = System::Drawing::Size(554, 265);
			this->textBox_ScriptText->TabIndex = 3;
			this->textBox_ScriptText->Text = L"Enter script here (or Download Script)\r\n";
			// 
			// tabPage_Bots
			// 
			this->tabPage_Bots->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tabPage_Bots->Controls->Add(this->groupBox2);
			this->tabPage_Bots->Controls->Add(this->groupBox1);
			this->tabPage_Bots->Controls->Add(this->groupBox5);
			this->tabPage_Bots->Controls->Add(this->groupBox6);
			this->tabPage_Bots->Controls->Add(this->groupBox3);
			this->tabPage_Bots->Controls->Add(this->groupBox_Reviver);
			this->tabPage_Bots->Controls->Add(this->groupBox_BotProfile);
			this->tabPage_Bots->Controls->Add(this->groupBox_TimedShutdown);
			this->tabPage_Bots->Location = System::Drawing::Point(4, 23);
			this->tabPage_Bots->Name = L"tabPage_Bots";
			this->tabPage_Bots->Size = System::Drawing::Size(558, 386);
			this->tabPage_Bots->TabIndex = 3;
			this->tabPage_Bots->Text = L"Bots";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_SetAttackSkill);
			this->groupBox2->Controls->Add(this->radioButton_IsMelee);
			this->groupBox2->Controls->Add(this->radioButton_IsRanged);
			this->groupBox2->Controls->Add(this->textBox_MainAttack);
			this->groupBox2->Location = System::Drawing::Point(121, 93);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(286, 118);
			this->groupBox2->TabIndex = 14;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Attack Skills";
			// 
			// button_SetAttackSkill
			// 
			this->button_SetAttackSkill->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button_SetAttackSkill->Location = System::Drawing::Point(112, 18);
			this->button_SetAttackSkill->Name = L"button_SetAttackSkill";
			this->button_SetAttackSkill->Size = System::Drawing::Size(56, 21);
			this->button_SetAttackSkill->TabIndex = 4;
			this->button_SetAttackSkill->Text = L"Set";
			this->button_SetAttackSkill->UseVisualStyleBackColor = true;
			this->button_SetAttackSkill->Click += gcnew System::EventHandler(this, &MyForm::button_SetAttackSkill_Click);
			// 
			// radioButton_IsMelee
			// 
			this->radioButton_IsMelee->AutoSize = true;
			this->radioButton_IsMelee->Checked = true;
			this->radioButton_IsMelee->Location = System::Drawing::Point(6, 44);
			this->radioButton_IsMelee->Name = L"radioButton_IsMelee";
			this->radioButton_IsMelee->Size = System::Drawing::Size(56, 18);
			this->radioButton_IsMelee->TabIndex = 3;
			this->radioButton_IsMelee->TabStop = true;
			this->radioButton_IsMelee->Text = L"Melee";
			this->radioButton_IsMelee->UseVisualStyleBackColor = true;
			// 
			// radioButton_IsRanged
			// 
			this->radioButton_IsRanged->AutoSize = true;
			this->radioButton_IsRanged->Location = System::Drawing::Point(6, 68);
			this->radioButton_IsRanged->Name = L"radioButton_IsRanged";
			this->radioButton_IsRanged->Size = System::Drawing::Size(65, 18);
			this->radioButton_IsRanged->TabIndex = 2;
			this->radioButton_IsRanged->Text = L"Ranged";
			this->radioButton_IsRanged->UseVisualStyleBackColor = true;
			// 
			// textBox_MainAttack
			// 
			this->textBox_MainAttack->Location = System::Drawing::Point(6, 18);
			this->textBox_MainAttack->Name = L"textBox_MainAttack";
			this->textBox_MainAttack->Size = System::Drawing::Size(100, 21);
			this->textBox_MainAttack->TabIndex = 1;
			this->textBox_MainAttack->Text = L"35969";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_Int);
			this->groupBox1->Controls->Add(this->label_Dex);
			this->groupBox1->Controls->Add(this->label_Str);
			this->groupBox1->Controls->Add(this->label_Exp);
			this->groupBox1->Controls->Add(this->label_Lvl);
			this->groupBox1->Controls->Add(this->checkBox_LogCharacterInfo);
			this->groupBox1->Controls->Add(this->label_CurrentArea);
			this->groupBox1->Controls->Add(this->label_Y);
			this->groupBox1->Controls->Add(this->label_X);
			this->groupBox1->Location = System::Drawing::Point(105, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(302, 84);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Character Info";
			// 
			// label_Int
			// 
			this->label_Int->AutoSize = true;
			this->label_Int->Location = System::Drawing::Point(226, 61);
			this->label_Int->Name = L"label_Int";
			this->label_Int->Size = System::Drawing::Size(24, 14);
			this->label_Int->TabIndex = 8;
			this->label_Int->Text = L"Int:";
			// 
			// label_Dex
			// 
			this->label_Dex->AutoSize = true;
			this->label_Dex->Location = System::Drawing::Point(224, 39);
			this->label_Dex->Name = L"label_Dex";
			this->label_Dex->Size = System::Drawing::Size(29, 14);
			this->label_Dex->TabIndex = 7;
			this->label_Dex->Text = L"Dex:";
			// 
			// label_Str
			// 
			this->label_Str->AutoSize = true;
			this->label_Str->Location = System::Drawing::Point(224, 17);
			this->label_Str->Name = L"label_Str";
			this->label_Str->Size = System::Drawing::Size(24, 14);
			this->label_Str->TabIndex = 6;
			this->label_Str->Text = L"Str:";
			// 
			// label_Exp
			// 
			this->label_Exp->AutoSize = true;
			this->label_Exp->Location = System::Drawing::Point(87, 39);
			this->label_Exp->Name = L"label_Exp";
			this->label_Exp->Size = System::Drawing::Size(28, 14);
			this->label_Exp->TabIndex = 5;
			this->label_Exp->Text = L"Exp:";
			// 
			// label_Lvl
			// 
			this->label_Lvl->AutoSize = true;
			this->label_Lvl->Location = System::Drawing::Point(87, 17);
			this->label_Lvl->Name = L"label_Lvl";
			this->label_Lvl->Size = System::Drawing::Size(35, 14);
			this->label_Lvl->TabIndex = 4;
			this->label_Lvl->Text = L"Level:";
			// 
			// checkBox_LogCharacterInfo
			// 
			this->checkBox_LogCharacterInfo->AutoSize = true;
			this->checkBox_LogCharacterInfo->Location = System::Drawing::Point(151, 59);
			this->checkBox_LogCharacterInfo->Name = L"checkBox_LogCharacterInfo";
			this->checkBox_LogCharacterInfo->Size = System::Drawing::Size(69, 18);
			this->checkBox_LogCharacterInfo->TabIndex = 3;
			this->checkBox_LogCharacterInfo->Text = L"Log Info";
			this->checkBox_LogCharacterInfo->UseVisualStyleBackColor = true;
			this->checkBox_LogCharacterInfo->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_LogCharacterInfo_CheckedChanged);
			// 
			// label_CurrentArea
			// 
			this->label_CurrentArea->AutoSize = true;
			this->label_CurrentArea->Location = System::Drawing::Point(6, 60);
			this->label_CurrentArea->Name = L"label_CurrentArea";
			this->label_CurrentArea->Size = System::Drawing::Size(36, 14);
			this->label_CurrentArea->TabIndex = 2;
			this->label_CurrentArea->Text = L"Area: ";
			// 
			// label_Y
			// 
			this->label_Y->AutoSize = true;
			this->label_Y->Location = System::Drawing::Point(6, 39);
			this->label_Y->Name = L"label_Y";
			this->label_Y->Size = System::Drawing::Size(15, 14);
			this->label_Y->TabIndex = 1;
			this->label_Y->Text = L"Y:";
			// 
			// label_X
			// 
			this->label_X->AutoSize = true;
			this->label_X->Location = System::Drawing::Point(6, 17);
			this->label_X->Name = L"label_X";
			this->label_X->Size = System::Drawing::Size(19, 14);
			this->label_X->TabIndex = 0;
			this->label_X->Text = L"X: ";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->numericUpDown_AreaToBot);
			this->groupBox5->Controls->Add(this->checkBox_EnableBot);
			this->groupBox5->Controls->Add(this->comboBox_BotType);
			this->groupBox5->Location = System::Drawing::Point(4, 0);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(95, 87);
			this->groupBox5->TabIndex = 12;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Controller";
			// 
			// numericUpDown_AreaToBot
			// 
			this->numericUpDown_AreaToBot->Location = System::Drawing::Point(5, 40);
			this->numericUpDown_AreaToBot->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown_AreaToBot->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_AreaToBot->Name = L"numericUpDown_AreaToBot";
			this->numericUpDown_AreaToBot->Size = System::Drawing::Size(84, 21);
			this->numericUpDown_AreaToBot->TabIndex = 12;
			this->numericUpDown_AreaToBot->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 132, 0, 0, 0 });
			// 
			// checkBox_EnableBot
			// 
			this->checkBox_EnableBot->AutoSize = true;
			this->checkBox_EnableBot->Location = System::Drawing::Point(7, 64);
			this->checkBox_EnableBot->Name = L"checkBox_EnableBot";
			this->checkBox_EnableBot->Size = System::Drawing::Size(82, 18);
			this->checkBox_EnableBot->TabIndex = 11;
			this->checkBox_EnableBot->Text = L"Enable Bot";
			this->checkBox_EnableBot->UseVisualStyleBackColor = true;
			this->checkBox_EnableBot->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_EnableBot_CheckedChanged);
			// 
			// comboBox_BotType
			// 
			this->comboBox_BotType->FormattingEnabled = true;
			this->comboBox_BotType->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Generic", L"Rollback (Divination)", L"Rollback (Prophecy)",
					L"Rollback (6-link)"
			});
			this->comboBox_BotType->Location = System::Drawing::Point(5, 15);
			this->comboBox_BotType->Name = L"comboBox_BotType";
			this->comboBox_BotType->Size = System::Drawing::Size(84, 22);
			this->comboBox_BotType->TabIndex = 10;
			this->comboBox_BotType->Text = L"Generic";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->textBox_ExtraAttacksSkillName);
			this->groupBox6->Controls->Add(this->listView_ExtraAttacks);
			this->groupBox6->Controls->Add(this->textBox_ExtraAttacksDelay);
			this->groupBox6->Controls->Add(this->textBox_ExtraAttackSkillID);
			this->groupBox6->Controls->Add(this->button_AddAttackSkill);
			this->groupBox6->Location = System::Drawing::Point(295, 260);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(255, 123);
			this->groupBox6->TabIndex = 11;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Buffs";
			// 
			// textBox_ExtraAttacksSkillName
			// 
			this->textBox_ExtraAttacksSkillName->Location = System::Drawing::Point(6, 69);
			this->textBox_ExtraAttacksSkillName->Name = L"textBox_ExtraAttacksSkillName";
			this->textBox_ExtraAttacksSkillName->Size = System::Drawing::Size(77, 21);
			this->textBox_ExtraAttacksSkillName->TabIndex = 16;
			this->textBox_ExtraAttacksSkillName->Text = L"Name";
			// 
			// listView_ExtraAttacks
			// 
			this->listView_ExtraAttacks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader8,
					this->columnHeader9, this->columnHeader10
			});
			this->listView_ExtraAttacks->FullRowSelect = true;
			this->listView_ExtraAttacks->GridLines = true;
			this->listView_ExtraAttacks->Location = System::Drawing::Point(88, 16);
			this->listView_ExtraAttacks->Name = L"listView_ExtraAttacks";
			this->listView_ExtraAttacks->Size = System::Drawing::Size(160, 101);
			this->listView_ExtraAttacks->TabIndex = 14;
			this->listView_ExtraAttacks->UseCompatibleStateImageBehavior = false;
			this->listView_ExtraAttacks->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Skill ID";
			this->columnHeader8->Width = 49;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"Name";
			this->columnHeader9->Width = 75;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"CD";
			// 
			// textBox_ExtraAttacksDelay
			// 
			this->textBox_ExtraAttacksDelay->Location = System::Drawing::Point(6, 44);
			this->textBox_ExtraAttacksDelay->Name = L"textBox_ExtraAttacksDelay";
			this->textBox_ExtraAttacksDelay->Size = System::Drawing::Size(77, 21);
			this->textBox_ExtraAttacksDelay->TabIndex = 13;
			this->textBox_ExtraAttacksDelay->Text = L"Delay (MS)";
			// 
			// textBox_ExtraAttackSkillID
			// 
			this->textBox_ExtraAttackSkillID->Location = System::Drawing::Point(6, 18);
			this->textBox_ExtraAttackSkillID->Name = L"textBox_ExtraAttackSkillID";
			this->textBox_ExtraAttackSkillID->Size = System::Drawing::Size(77, 21);
			this->textBox_ExtraAttackSkillID->TabIndex = 2;
			this->textBox_ExtraAttackSkillID->Text = L"Skill ID";
			// 
			// button_AddAttackSkill
			// 
			this->button_AddAttackSkill->ForeColor = System::Drawing::Color::Black;
			this->button_AddAttackSkill->Location = System::Drawing::Point(6, 94);
			this->button_AddAttackSkill->Name = L"button_AddAttackSkill";
			this->button_AddAttackSkill->Size = System::Drawing::Size(77, 23);
			this->button_AddAttackSkill->TabIndex = 0;
			this->button_AddAttackSkill->Text = L"Add";
			this->button_AddAttackSkill->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox_TimedFlask4);
			this->groupBox3->Controls->Add(this->textBox_TimerFlask4);
			this->groupBox3->Controls->Add(this->checkBox_TimedFlask4);
			this->groupBox3->Controls->Add(this->listView_CurrentFlasks);
			this->groupBox3->Controls->Add(this->textBox_TimerFlask3);
			this->groupBox3->Controls->Add(this->textBox_TimerFlask2);
			this->groupBox3->Controls->Add(this->textBox_TimedFlask3);
			this->groupBox3->Controls->Add(this->textBox_TimedFlask2);
			this->groupBox3->Controls->Add(this->textBox_TimedFlask1);
			this->groupBox3->Controls->Add(this->textBox_TimerFlask1);
			this->groupBox3->Controls->Add(this->checkBox_TimedFlask3);
			this->groupBox3->Controls->Add(this->checkBox_TimedFlask2);
			this->groupBox3->Controls->Add(this->checkBox_TimedFlask1);
			this->groupBox3->Controls->Add(this->numericUpDown_AutoMP);
			this->groupBox3->Controls->Add(this->numericUpDown_AutoHP);
			this->groupBox3->Controls->Add(this->checkBox_AutoHP);
			this->groupBox3->Controls->Add(this->textBox_BeltSlotMP);
			this->groupBox3->Controls->Add(this->textBox_BeltSlotHP);
			this->groupBox3->Controls->Add(this->checkBox_AutoMP);
			this->groupBox3->Location = System::Drawing::Point(4, 217);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(285, 166);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Flasks";
			// 
			// textBox_TimedFlask4
			// 
			this->textBox_TimedFlask4->Location = System::Drawing::Point(147, 134);
			this->textBox_TimedFlask4->Name = L"textBox_TimedFlask4";
			this->textBox_TimedFlask4->Size = System::Drawing::Size(54, 21);
			this->textBox_TimedFlask4->TabIndex = 21;
			this->textBox_TimedFlask4->Text = L"Belt Slot";
			// 
			// textBox_TimerFlask4
			// 
			this->textBox_TimerFlask4->Location = System::Drawing::Point(94, 134);
			this->textBox_TimerFlask4->Name = L"textBox_TimerFlask4";
			this->textBox_TimerFlask4->Size = System::Drawing::Size(47, 21);
			this->textBox_TimerFlask4->TabIndex = 20;
			// 
			// checkBox_TimedFlask4
			// 
			this->checkBox_TimedFlask4->AutoSize = true;
			this->checkBox_TimedFlask4->Location = System::Drawing::Point(5, 135);
			this->checkBox_TimedFlask4->Name = L"checkBox_TimedFlask4";
			this->checkBox_TimedFlask4->Size = System::Drawing::Size(67, 18);
			this->checkBox_TimedFlask4->TabIndex = 19;
			this->checkBox_TimedFlask4->Text = L"Sulphur";
			this->checkBox_TimedFlask4->UseVisualStyleBackColor = true;
			// 
			// listView_CurrentFlasks
			// 
			this->listView_CurrentFlasks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader3,
					this->columnHeader4
			});
			this->listView_CurrentFlasks->FullRowSelect = true;
			this->listView_CurrentFlasks->GridLines = true;
			this->listView_CurrentFlasks->Location = System::Drawing::Point(208, 17);
			this->listView_CurrentFlasks->Name = L"listView_CurrentFlasks";
			this->listView_CurrentFlasks->Size = System::Drawing::Size(70, 136);
			this->listView_CurrentFlasks->TabIndex = 18;
			this->listView_CurrentFlasks->UseCompatibleStateImageBehavior = false;
			this->listView_CurrentFlasks->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Type";
			this->columnHeader3->Width = 39;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Slot";
			this->columnHeader4->Width = 31;
			// 
			// textBox_TimerFlask3
			// 
			this->textBox_TimerFlask3->Location = System::Drawing::Point(94, 110);
			this->textBox_TimerFlask3->Name = L"textBox_TimerFlask3";
			this->textBox_TimerFlask3->Size = System::Drawing::Size(47, 21);
			this->textBox_TimerFlask3->TabIndex = 17;
			// 
			// textBox_TimerFlask2
			// 
			this->textBox_TimerFlask2->Location = System::Drawing::Point(94, 87);
			this->textBox_TimerFlask2->Name = L"textBox_TimerFlask2";
			this->textBox_TimerFlask2->Size = System::Drawing::Size(47, 21);
			this->textBox_TimerFlask2->TabIndex = 16;
			// 
			// textBox_TimedFlask3
			// 
			this->textBox_TimedFlask3->Location = System::Drawing::Point(147, 110);
			this->textBox_TimedFlask3->Name = L"textBox_TimedFlask3";
			this->textBox_TimedFlask3->Size = System::Drawing::Size(54, 21);
			this->textBox_TimedFlask3->TabIndex = 15;
			this->textBox_TimedFlask3->Text = L"Belt Slot";
			// 
			// textBox_TimedFlask2
			// 
			this->textBox_TimedFlask2->Location = System::Drawing::Point(147, 87);
			this->textBox_TimedFlask2->Name = L"textBox_TimedFlask2";
			this->textBox_TimedFlask2->Size = System::Drawing::Size(54, 21);
			this->textBox_TimedFlask2->TabIndex = 14;
			this->textBox_TimedFlask2->Text = L"Belt Slot";
			// 
			// textBox_TimedFlask1
			// 
			this->textBox_TimedFlask1->Location = System::Drawing::Point(147, 64);
			this->textBox_TimedFlask1->Name = L"textBox_TimedFlask1";
			this->textBox_TimedFlask1->Size = System::Drawing::Size(54, 21);
			this->textBox_TimedFlask1->TabIndex = 13;
			this->textBox_TimedFlask1->Text = L"Belt Slot";
			// 
			// textBox_TimerFlask1
			// 
			this->textBox_TimerFlask1->Location = System::Drawing::Point(94, 64);
			this->textBox_TimerFlask1->Name = L"textBox_TimerFlask1";
			this->textBox_TimerFlask1->Size = System::Drawing::Size(47, 21);
			this->textBox_TimerFlask1->TabIndex = 12;
			// 
			// checkBox_TimedFlask3
			// 
			this->checkBox_TimedFlask3->AutoSize = true;
			this->checkBox_TimedFlask3->Location = System::Drawing::Point(5, 112);
			this->checkBox_TimedFlask3->Name = L"checkBox_TimedFlask3";
			this->checkBox_TimedFlask3->Size = System::Drawing::Size(53, 18);
			this->checkBox_TimedFlask3->TabIndex = 11;
			this->checkBox_TimedFlask3->Text = L"Silver";
			this->checkBox_TimedFlask3->UseVisualStyleBackColor = true;
			// 
			// checkBox_TimedFlask2
			// 
			this->checkBox_TimedFlask2->AutoSize = true;
			this->checkBox_TimedFlask2->Location = System::Drawing::Point(5, 89);
			this->checkBox_TimedFlask2->Name = L"checkBox_TimedFlask2";
			this->checkBox_TimedFlask2->Size = System::Drawing::Size(61, 18);
			this->checkBox_TimedFlask2->TabIndex = 10;
			this->checkBox_TimedFlask2->Text = L"Quartz";
			this->checkBox_TimedFlask2->UseVisualStyleBackColor = true;
			// 
			// checkBox_TimedFlask1
			// 
			this->checkBox_TimedFlask1->AutoSize = true;
			this->checkBox_TimedFlask1->Location = System::Drawing::Point(5, 65);
			this->checkBox_TimedFlask1->Name = L"checkBox_TimedFlask1";
			this->checkBox_TimedFlask1->Size = System::Drawing::Size(82, 18);
			this->checkBox_TimedFlask1->TabIndex = 9;
			this->checkBox_TimedFlask1->Text = L"Quicksilver";
			this->checkBox_TimedFlask1->UseVisualStyleBackColor = true;
			// 
			// numericUpDown_AutoMP
			// 
			this->numericUpDown_AutoMP->DecimalPlaces = 1;
			this->numericUpDown_AutoMP->Location = System::Drawing::Point(94, 40);
			this->numericUpDown_AutoMP->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_AutoMP->Name = L"numericUpDown_AutoMP";
			this->numericUpDown_AutoMP->Size = System::Drawing::Size(47, 21);
			this->numericUpDown_AutoMP->TabIndex = 8;
			this->numericUpDown_AutoMP->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// numericUpDown_AutoHP
			// 
			this->numericUpDown_AutoHP->DecimalPlaces = 1;
			this->numericUpDown_AutoHP->Location = System::Drawing::Point(94, 17);
			this->numericUpDown_AutoHP->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_AutoHP->Name = L"numericUpDown_AutoHP";
			this->numericUpDown_AutoHP->Size = System::Drawing::Size(47, 21);
			this->numericUpDown_AutoHP->TabIndex = 7;
			this->numericUpDown_AutoHP->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// checkBox_AutoHP
			// 
			this->checkBox_AutoHP->AutoSize = true;
			this->checkBox_AutoHP->Location = System::Drawing::Point(5, 20);
			this->checkBox_AutoHP->Name = L"checkBox_AutoHP";
			this->checkBox_AutoHP->Size = System::Drawing::Size(88, 18);
			this->checkBox_AutoHP->TabIndex = 0;
			this->checkBox_AutoHP->Text = L"Auto HP Pot";
			this->checkBox_AutoHP->UseVisualStyleBackColor = true;
			// 
			// textBox_BeltSlotMP
			// 
			this->textBox_BeltSlotMP->Location = System::Drawing::Point(147, 41);
			this->textBox_BeltSlotMP->Name = L"textBox_BeltSlotMP";
			this->textBox_BeltSlotMP->Size = System::Drawing::Size(54, 21);
			this->textBox_BeltSlotMP->TabIndex = 6;
			this->textBox_BeltSlotMP->Text = L"Belt Slot";
			// 
			// textBox_BeltSlotHP
			// 
			this->textBox_BeltSlotHP->Location = System::Drawing::Point(147, 18);
			this->textBox_BeltSlotHP->Name = L"textBox_BeltSlotHP";
			this->textBox_BeltSlotHP->Size = System::Drawing::Size(54, 21);
			this->textBox_BeltSlotHP->TabIndex = 5;
			this->textBox_BeltSlotHP->Text = L"Belt Slot";
			// 
			// checkBox_AutoMP
			// 
			this->checkBox_AutoMP->AutoSize = true;
			this->checkBox_AutoMP->Location = System::Drawing::Point(5, 42);
			this->checkBox_AutoMP->Name = L"checkBox_AutoMP";
			this->checkBox_AutoMP->Size = System::Drawing::Size(90, 18);
			this->checkBox_AutoMP->TabIndex = 1;
			this->checkBox_AutoMP->Text = L"Auto MP Pot";
			this->checkBox_AutoMP->UseVisualStyleBackColor = true;
			// 
			// groupBox_Reviver
			// 
			this->groupBox_Reviver->Controls->Add(this->checkBox_CastBuffsOnRevive);
			this->groupBox_Reviver->Controls->Add(this->radioButton_ReviveWaypoint);
			this->groupBox_Reviver->Controls->Add(this->radioButton_ReviveTown);
			this->groupBox_Reviver->Controls->Add(this->checkBox_ReviveOnDeath);
			this->groupBox_Reviver->Location = System::Drawing::Point(413, 93);
			this->groupBox_Reviver->Name = L"groupBox_Reviver";
			this->groupBox_Reviver->Size = System::Drawing::Size(137, 118);
			this->groupBox_Reviver->TabIndex = 5;
			this->groupBox_Reviver->TabStop = false;
			this->groupBox_Reviver->Text = L"Death Controller";
			// 
			// checkBox_CastBuffsOnRevive
			// 
			this->checkBox_CastBuffsOnRevive->AutoSize = true;
			this->checkBox_CastBuffsOnRevive->Location = System::Drawing::Point(6, 93);
			this->checkBox_CastBuffsOnRevive->Name = L"checkBox_CastBuffsOnRevive";
			this->checkBox_CastBuffsOnRevive->Size = System::Drawing::Size(129, 18);
			this->checkBox_CastBuffsOnRevive->TabIndex = 4;
			this->checkBox_CastBuffsOnRevive->Text = L"Use Buffs On Revive";
			this->checkBox_CastBuffsOnRevive->UseVisualStyleBackColor = true;
			// 
			// radioButton_ReviveWaypoint
			// 
			this->radioButton_ReviveWaypoint->AutoSize = true;
			this->radioButton_ReviveWaypoint->Location = System::Drawing::Point(23, 68);
			this->radioButton_ReviveWaypoint->Name = L"radioButton_ReviveWaypoint";
			this->radioButton_ReviveWaypoint->Size = System::Drawing::Size(84, 18);
			this->radioButton_ReviveWaypoint->TabIndex = 3;
			this->radioButton_ReviveWaypoint->TabStop = true;
			this->radioButton_ReviveWaypoint->Text = L"Checkpoint";
			this->radioButton_ReviveWaypoint->UseVisualStyleBackColor = true;
			// 
			// radioButton_ReviveTown
			// 
			this->radioButton_ReviveTown->AutoSize = true;
			this->radioButton_ReviveTown->Location = System::Drawing::Point(23, 44);
			this->radioButton_ReviveTown->Name = L"radioButton_ReviveTown";
			this->radioButton_ReviveTown->Size = System::Drawing::Size(53, 18);
			this->radioButton_ReviveTown->TabIndex = 2;
			this->radioButton_ReviveTown->TabStop = true;
			this->radioButton_ReviveTown->Text = L"Town";
			this->radioButton_ReviveTown->UseVisualStyleBackColor = true;
			// 
			// checkBox_ReviveOnDeath
			// 
			this->checkBox_ReviveOnDeath->AutoSize = true;
			this->checkBox_ReviveOnDeath->Location = System::Drawing::Point(6, 20);
			this->checkBox_ReviveOnDeath->Name = L"checkBox_ReviveOnDeath";
			this->checkBox_ReviveOnDeath->Size = System::Drawing::Size(111, 18);
			this->checkBox_ReviveOnDeath->TabIndex = 1;
			this->checkBox_ReviveOnDeath->Text = L"Revive On Death";
			this->checkBox_ReviveOnDeath->UseVisualStyleBackColor = true;
			this->checkBox_ReviveOnDeath->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_ReviveOnDeath_CheckedChanged);
			// 
			// groupBox_BotProfile
			// 
			this->groupBox_BotProfile->Controls->Add(this->button_SaveProfile);
			this->groupBox_BotProfile->Controls->Add(this->button_LoadProfile);
			this->groupBox_BotProfile->Location = System::Drawing::Point(413, 3);
			this->groupBox_BotProfile->Name = L"groupBox_BotProfile";
			this->groupBox_BotProfile->Size = System::Drawing::Size(137, 84);
			this->groupBox_BotProfile->TabIndex = 4;
			this->groupBox_BotProfile->TabStop = false;
			this->groupBox_BotProfile->Text = L"Bot Profiles";
			// 
			// button_SaveProfile
			// 
			this->button_SaveProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_SaveProfile.Image")));
			this->button_SaveProfile->Location = System::Drawing::Point(73, 20);
			this->button_SaveProfile->Name = L"button_SaveProfile";
			this->button_SaveProfile->Size = System::Drawing::Size(59, 52);
			this->button_SaveProfile->TabIndex = 5;
			this->button_SaveProfile->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button_SaveProfile->UseVisualStyleBackColor = true;
			// 
			// button_LoadProfile
			// 
			this->button_LoadProfile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_LoadProfile.Image")));
			this->button_LoadProfile->Location = System::Drawing::Point(7, 20);
			this->button_LoadProfile->Name = L"button_LoadProfile";
			this->button_LoadProfile->Size = System::Drawing::Size(59, 52);
			this->button_LoadProfile->TabIndex = 4;
			this->button_LoadProfile->UseVisualStyleBackColor = true;
			// 
			// groupBox_TimedShutdown
			// 
			this->groupBox_TimedShutdown->Controls->Add(this->checkBox2);
			this->groupBox_TimedShutdown->Controls->Add(this->checkBox1);
			this->groupBox_TimedShutdown->Controls->Add(this->checkBox_TimedProcessClose);
			this->groupBox_TimedShutdown->Controls->Add(this->dateTimePicker_Shutdown);
			this->groupBox_TimedShutdown->Location = System::Drawing::Point(4, 93);
			this->groupBox_TimedShutdown->Name = L"groupBox_TimedShutdown";
			this->groupBox_TimedShutdown->Size = System::Drawing::Size(111, 118);
			this->groupBox_TimedShutdown->TabIndex = 3;
			this->groupBox_TimedShutdown->TabStop = false;
			this->groupBox_TimedShutdown->Text = L"Timed Shutdown";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->ForeColor = System::Drawing::Color::Lime;
			this->checkBox2->Location = System::Drawing::Point(6, 93);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(78, 18);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->Text = L"Sleep CPU";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::Color::Red;
			this->checkBox1->Location = System::Drawing::Point(6, 71);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(104, 18);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Shutdown CPU";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox_TimedProcessClose
			// 
			this->checkBox_TimedProcessClose->AutoSize = true;
			this->checkBox_TimedProcessClose->Location = System::Drawing::Point(6, 47);
			this->checkBox_TimedProcessClose->Name = L"checkBox_TimedProcessClose";
			this->checkBox_TimedProcessClose->Size = System::Drawing::Size(82, 18);
			this->checkBox_TimedProcessClose->TabIndex = 1;
			this->checkBox_TimedProcessClose->Text = L"Kill Process";
			this->checkBox_TimedProcessClose->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker_Shutdown
			// 
			this->dateTimePicker_Shutdown->Location = System::Drawing::Point(6, 20);
			this->dateTimePicker_Shutdown->Name = L"dateTimePicker_Shutdown";
			this->dateTimePicker_Shutdown->Size = System::Drawing::Size(89, 21);
			this->dateTimePicker_Shutdown->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(590, 437);
			this->ControlBox = false;
			this->Controls->Add(this->tabControl1);
			this->Cursor = System::Windows::Forms::Cursors::PanNE;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::Control;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Bot Of Exile (3.9.1b)";
			this->TopMost = true;
			this->TransparencyKey = System::Drawing::Color::Coral;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage_Hacks->ResumeLayout(false);
			this->groupBox_Exploits->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_HideoutID))->EndInit();
			this->groupBox_Hotkeys->ResumeLayout(false);
			this->groupBox_Hotkeys->PerformLayout();
			this->groupBox_UtilityHacks->ResumeLayout(false);
			this->groupBox_UtilityHacks->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CPUReducer))->EndInit();
			this->groupBox_Maphacks->ResumeLayout(false);
			this->groupBox_Maphacks->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CharSize))->EndInit();
			this->tabPage_Packets->ResumeLayout(false);
			this->contextMenuStrip_PacketLog->ResumeLayout(false);
			this->tabPage_LUA->ResumeLayout(false);
			this->tabPage_LUA->PerformLayout();
			this->tabPage_Bots->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AreaToBot))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AutoMP))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AutoHP))->EndInit();
			this->groupBox_Reviver->ResumeLayout(false);
			this->groupBox_Reviver->PerformLayout();
			this->groupBox_BotProfile->ResumeLayout(false);
			this->groupBox_TimedShutdown->ResumeLayout(false);
			this->groupBox_TimedShutdown->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

public: System::Void ProcessSendQueue() {

	SendPacketQueue.empty();

	while (true)
	{
		if (IsLoggingSendPackets)
		{
			if (SendPacketQueue.size() > 0) 
			{

				PacketWriter* sendPacket = SendPacketQueue.front();

				wchar_t *pwDataText;
				wchar_t pwLengthText[10];

				CHAR* packetString = convertPacketFormatToString((unsigned char*)sendPacket->GetBuffer(), sendPacket->GetSize());

				DWORD dwNum = MultiByteToWideChar(CP_UTF8, 0, packetString, -1, NULL, 0);
				_itow_s(sendPacket->GetSize(), pwLengthText, 10);

				pwDataText = new wchar_t[dwNum];
				MultiByteToWideChar(CP_UTF8, 0, packetString, -1, pwDataText, dwNum);

				String ^dataString = gcnew String(pwDataText);
				String ^lengthString = gcnew String(pwLengthText);
				String ^OpcodeString = gcnew String("Opcode");

				array<String^>^ subItems = gcnew array<String^>(3);
				subItems[0] = gcnew String(lengthString);
				subItems[1] = gcnew String(OpcodeString);
				subItems[2] = gcnew String(dataString);

				ListViewItem^ itm = gcnew ListViewItem(subItems);
				this->listView_SendPacketLog->Items->Add(itm);

				SendPacketQueue.pop();
				delete sendPacket;
				delete[] pwDataText;
				delete dataString;
				delete lengthString;
				delete OpcodeString;
				delete subItems;
				delete itm;
				free(packetString);
			}
			else
				Thread::Sleep(300);
		}
		else
		{
			if (SendPacketQueue.size() > 0)
			{
				for (int i = 0; i < SendPacketQueue.size(); i++)
				{
					SendPacketQueue.pop();
				}
			}

			Sleep(1000);
		}
	}
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {


	/*if (!BotBase::GetInstance()->GetNetSender()->CompareHardwareID())
	{
		printf("INVALID HWID!!!!111 GET OOT YE TRASPASSER\n");
	}*/

	UINT64 PoEBase = (UINT64)GetModuleHandle(NULL);

	//Entity spawn. Todo: Clean this up into one func.
	//PrepareAndSetHook(uint64 address, uint64 returnaddress, uint64 hookfunc, uint64 callback func, CHAR* hooknameOptional);
	SetEntitySpawnHookReturnAddress(PoEBase + EntitySpawnOffset + 7);
	SetEntitySpawnHookCallbackAddress((UINT64)MappingBot::HandleEntitySpawn);
	//SetHook(PoEBase + EntitySpawnOffset, EntitySpawnHook, "EntitySpawn");

	//WriteFile
	SetWriteFileHookReturnAddress(PoEBase + LogDebugFileOutputOffset + 5);
	SetWriteFileHookCallbackAddress((UINT64)MappingBot::HandleClientTxtLogs);
	//SetHook(PoEBase + LogDebugFileOutputOffset, WriteFileHook, "WriteFile");

	SetSendActionAddress(PoEBase + SendPlayerActionOffset);

	//SendPacket
	MoveCreatePacketAddress((UINT64)CreatePacket);
	MoveSendPacketReturnAddress((UINT64)(LogSendReturnOffset + PoEBase));
	MoveSendPacketAddress(SendPacketFuncOffset + PoEBase);
	SetHook(PoEBase + LogSendOffset, LogSendPacketHook, "LogSend");

	//Autopot/CPUReducer/mainthreadhook
	UINT64 AutoPotHookAddress = PoEBase + CurrentHPMPAddressOffset;
	MoveAutoPotReturnHookAddress(AutoPotHookAddress + 8);
	MoveAutoPotCallbackHookAddress((UINT64)MappingBot::HandleCurrentHPMP);
	//SetHook(AutoPotHookAddress, GetCurrentHPMPHook, "HPMP");


	//RemovePeHeader causes .NET crash
	CHAR dllName[] = "BotOfExile.dll";
	WCHAR wdllName[] = L"BotOfExile.dll";
	ULONG len = (ULONG)strlen(dllName);
	//DisableThreadLibraryCalls(hDLLModule);
	//UnlinkModule(dllName);
	//ChangeDLLNameRuntime(wdllName, L"shit.gpk");
	//RemovePeHeader(GetModuleHandleA("BotOfExile.dll"));
	//printf("PE Header removed..\n");
	printf("Module unlinked...\n");
	ZeroMemory(dllName, len);

}

private: System::Void LogCharacterInfo()
{
	MappingBot* mb = (MappingBot*)BotBase::GetInstance();

	while (this->checkBox_LogCharacterInfo->Checked)
	{
		Entity* ent = LocalActor::GetEntityFromCharacterBasePtr();
		Player* p = new Player();
		UINT32 STR = p->GetStr(ent);
		UINT32 DEX = p->GetDex(ent);
		UINT32 INT = p->GetInt(ent);
		byte Level = p->GetLevel(ent);
		Vector2* v2 = Entity::GetEntityGridPosition(ent);
		UINT32 Exp = p->GetExperience(ent);
		UINT16 Area = mb->ActorPath->GetCurrentArea();

		this->label_Str->Text = "Str: " + STR;
		this->label_Dex->Text = "Dex: " + DEX;
		this->label_Int->Text = "Int: " + INT;
		this->label_Lvl->Text = "Level: " + Level;
		this->label_Exp->Text = "Exp: " + Exp;
		this->label_X->Text = "X: " + v2->X;
		this->label_Y->Text = "Y: " + v2->Y;
		this->label_CurrentArea->Text = "Area: " + Area;


		delete ent; ent = nullptr;
		delete p; p = nullptr;
		delete v2; v2 = nullptr;
		Sleep(200);
	}
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	MappingBot* mb = (MappingBot*)BotBase::GetInstance();

	Entity* ent = LocalActor::GetEntityFromCharacterBasePtr();

	if (ent != NULL)
	{
		printf("Local Actor ID: %x\n", ent->GetEntityID());

		printf("LifeAddr: %llX, Current: %d, Max: %d, CurrentMP: %d, MaxMP: %d\n", ent->GetMemoryAddress(), Life::GetCurrentHP(ent), Life::GetMaxHP(ent), Life::GetCurrentMP(ent), Life::GetMaxMP(ent));
	
		Player* p = new Player();
		UINT32 STR = p->GetStr(ent);
		UINT32 DEX = p->GetDex(ent);
		UINT32 INT = p->GetInt(ent);
		printf("Str: %d, Dex: %d, Int: %d, Lvl: %d ", STR, DEX, INT, p->GetLevel(ent));
		printf("Prophecies: %d\n", p->GetProphecyCount(ent));

		UINT64 Addr = ent->GetComponentAddress("Positioned");
		printf("Char positioned: %llX\n", Addr);

		ent->GetComponentList();
		
		for each (ComponentListNode c in ent->GetComponentList())
		{
			UINT64 ComponentAddress = ent->GetComponentAddress((char*)c.NamePtr);
			printf("Component: %s, Address: %llX\n", c.NamePtr, ComponentAddress);
		}
		delete p; p = nullptr;
	}
	
	delete ent; ent = nullptr;

}
private: System::Void checkBox_RevealMap_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	UINT64 PoEBase = (UINT64)GetModuleHandle(NULL);
	UINT64 MHAddress = PoEBase + MaphackAddressOffset;
	HACK Maphack = { MHAddress, "\x00", "\x01", 1 };

	if (this->checkBox_RevealMap->Checked == TRUE)
	{
		WriteHackBytes(Maphack, TRUE);
	}
	else
	{
		WriteHackBytes(Maphack, FALSE);
	}
}
private: System::Void button_OpenPacketGUI_Click(System::Object^  sender, System::EventArgs^  e) {

	PacketWindow = gcnew PacketControls;
	PacketWindow->Show();

	SendPacketsLogThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ProcessSendQueue));
	SendPacketsLogThread->Start();
}
private: System::Void checkBox_LogEntitySpawn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	UINT64 PoEBase = (UINT64)GetModuleHandle(NULL);

	if (this->checkBox_LogEntitySpawn->Checked == TRUE)
	{
		if (this->radioButton_LogComponents->Checked == TRUE)
		{
			IsLoggingComponents = TRUE;
		}

		SetHook(PoEBase + EntitySpawnOffset, EntitySpawnHook, "EntitySpawn");
	}
	else
	{
		IsLoggingComponents = FALSE;
		//RemoveHook(PoEBase + EntitySpawnOffset, 7, (BYTE*)"\x48\x81\xEC\xC0\x00\x00\x00");
	}
}
private: System::Void checkBox_RAMReducer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_RAMReducer->Checked == TRUE)
	{
		ReduceRAMThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&ReduceRAM, 0, 0, 0);
	}
	else
	{
		TerminateThread(ReduceRAMThread, 0);
		ReduceRAMThread = NULL;
	}
}
private: System::Void radioButton_LogComponents_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void clearListToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	this->listView_SendPacketLog->Items->Clear();
}

private: System::Void copySendPacket() {

	ListViewItem^ selectedItem;

	for (int i = 0; i < listView_SendPacketLog->Items->Count; i++)
	{
		selectedItem = listView_SendPacketLog->Items[i];

		if (selectedItem->Selected == true)
		{
			String^ packetString = selectedItem->SubItems[2]->Text;
			Clipboard::SetDataObject(packetString, true);
		}
	}
}

private: System::Void copySelectedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	Thread^ newThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::copySendPacket));
	newThread->SetApartmentState(System::Threading::ApartmentState::STA);
	newThread->Start();
}
private: System::Void checkBox_UseFlare_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_UseFlare->Checked == TRUE) //hotkey bind
	{

	}
	else
	{

	}
}
private: System::Void checkBox_UseDynamite_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_UseDynamite->Checked == TRUE)
	{

	}
	else 
	{

	}
}
private: System::Void button_RunScript_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ scriptText = this->textBox_ScriptText->Text;
	char* scriptBuffer = (char*)(void*)Marshal::StringToHGlobalAnsi(scriptText);
	//ScriptThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&execute_lua, (LPVOID)scriptBuffer, 0, 0);

}
private: System::Void checkBox_LogMonsterInfo_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_LogMonsterInfo->Checked == TRUE)
	{

	}
	else
	{

	}
}
private: System::Void checkBox_ZoomHack_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	UINT64 PoEBase = (UINT64)GetModuleHandle(NULL);
	HACK hkZoomHack = { PoEBase + ZoomHackOffset, "\x9B", "\x8B", 1 };

	if (this->checkBox_ZoomHack->Checked == TRUE)
	{	
		WriteHackBytes(hkZoomHack, TRUE);
	}
	else
	{
		WriteHackBytes(hkZoomHack, FALSE);
	}
}
private: System::Void checkBox_LightsExpanse_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	UINT64 PoEBase = (UINT64)GetModuleHandle(NULL);
	HACK hkExpanseLights = { PoEBase + MapLightExpanseOffset, "\x66\x0F\x6E\x9C\x24\xB8\x00\x00\x00", "\xF3\x0F\x5E\xDC\x90\x90\x90\x90\x90", 9 };

	if (this->checkBox_LightsExpanse->Checked)
	{
		WriteHackBytes(hkExpanseLights, TRUE);
	}
	else
	{
		WriteHackBytes(hkExpanseLights, FALSE);
	}
}
private: System::Void button_SetCharSize_Click(System::Object^  sender, System::EventArgs^  e) {

	double Size = Convert::ToDouble(this->numericUpDown_CharSize->Value);
	Entity* ent = LocalActor::GetEntityFromCharacterBasePtr();
	Positioned::SetEntitySize(ent, Size);
	delete ent;
}

private: System::Void checkBox_LogCharacterInfo_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_LogCharacterInfo->Checked == TRUE)
	{
		LogInfoThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::LogCharacterInfo));
		LogInfoThread->Start();
	}
	else
	{
		LogInfoThread->Abort();
	}
}
private: System::Void button_SwapHideout_Click(System::Object^  sender, System::EventArgs^  e) {

	LocalActor::ChangeHideout(Convert::ToByte(this->numericUpDown_AutoHP->Value));
}
private: System::Void checkBox_EnableBot_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	MappingBot* mb = (MappingBot*)BotBase::GetInstance();

	if (this->checkBox_EnableBot->Checked == TRUE)
	{
		String^ Type = this->comboBox_BotType->Text;
		UINT16 AreaToBot = Convert::ToInt16(this->numericUpDown_AreaToBot->Value);
	
		mb->ActorPath->SetDestinationArea(AreaToBot);
		mb->isTrackingMonsters = TRUE;
		//mb->isAutoFlasking = TRUE;
		mb->isAutoLooting = TRUE;
		mb->isAutoMapping = TRUE;
		//mb->LifeTrackingThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&MappingBot::MonitorCharacterHealthMana, 0, 0, 0);
	}
	else
	{
		mb->ActorPath->SetDestinationArea(0);
		mb->isTrackingMonsters = FALSE;
		mb->isAutoFlasking = FALSE;
		mb->isAutoLooting = FALSE;
		mb->isAutoMapping = FALSE;
		//TerminateThread(mb->LifeTrackingThread, 0);
	}
}
private: System::Void button_SetAttackSkill_Click(System::Object^  sender, System::EventArgs^  e) {

	MappingBot* mb = (MappingBot*)BotBase::GetInstance();

	try
	{
		USHORT SkillID = Convert::ToUInt16(textBox_MainAttack->Text);
		mb->MainAttackSkillID = SkillID;
	}
	catch (...)
	{
		MessageBox::Show("Could not convert attack skill to number.");
	}

	BOOL IsMelee = FALSE;

	if (this->radioButton_IsMelee->Checked)
	{
		IsMelee = TRUE;
	}
	else if (this->radioButton_IsRanged->Checked)
	{
		IsMelee = FALSE;
	}
	else
		IsMelee = TRUE;

	
}
private: System::Void checkBox_ReviveOnDeath_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	MappingBot* mb = (MappingBot*)BotBase::GetInstance();

	if (this->checkBox_ReviveOnDeath->Checked)
	{
		mb->ReviveOnDeath = TRUE;

		if (this->radioButton_ReviveTown->Checked)
		{
			mb->ReviveCheckpointOrTown = TRUE;
		}
		else if (this->radioButton_ReviveWaypoint->Checked)
		{
			mb->ReviveCheckpointOrTown = FALSE;
		}
	}
	else
	{
		mb->ReviveOnDeath = FALSE;
	}
}
};
}