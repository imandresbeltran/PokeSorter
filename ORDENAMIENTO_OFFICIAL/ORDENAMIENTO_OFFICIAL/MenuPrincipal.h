#pragma once
#include "ProcesarArchivo.h"
#include "OrdenarListado.h"
#include "ListadoPokemon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <ctime>

ListadoPokemon pokemones;
OrdenarListado Ordenes;
ProcesarArchivo LecturaArch;

namespace ORDENAMIENTOOFFICIAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ txt_PantallaPokedex;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxT;
	private: System::Windows::Forms::Label^ labelDA;
	private: System::Windows::Forms::OpenFileDialog^ NombreArchivo;

	protected:
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->txt_PantallaPokedex = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxT = (gcnew System::Windows::Forms::TextBox());
			this->labelDA = (gcnew System::Windows::Forms::Label());
			this->NombreArchivo = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(23, 28);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(343, 530);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// txt_PantallaPokedex
			// 
			this->txt_PantallaPokedex->Location = System::Drawing::Point(51, 146);
			this->txt_PantallaPokedex->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txt_PantallaPokedex->Multiline = true;
			this->txt_PantallaPokedex->Name = L"txt_PantallaPokedex";
			this->txt_PantallaPokedex->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_PantallaPokedex->Size = System::Drawing::Size(288, 390);
			this->txt_PantallaPokedex->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(422, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 21);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Pokemons:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(424, 146);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 21);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Ordenar Por:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(425, 62);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 30);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Cargar nombres";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuPrincipal::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(425, 185);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(138, 30);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Nombres";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuPrincipal::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(425, 239);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(138, 30);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Generación";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MenuPrincipal::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(427, 302);
			this->button5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(208, 30);
			this->button5->TabIndex = 12;
			this->button5->Text = L"National Number";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MenuPrincipal::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(425, 516);
			this->button6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(138, 30);
			this->button6->TabIndex = 13;
			this->button6->Text = L"Salir";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MenuPrincipal::button6_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(422, 402);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 21);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Tiempo Recorrido:";
			// 
			// textBoxT
			// 
			this->textBoxT->Location = System::Drawing::Point(425, 443);
			this->textBoxT->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBoxT->Multiline = true;
			this->textBoxT->Name = L"textBoxT";
			this->textBoxT->Size = System::Drawing::Size(137, 36);
			this->textBoxT->TabIndex = 15;
			// 
			// labelDA
			// 
			this->labelDA->AutoSize = true;
			this->labelDA->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDA->Location = System::Drawing::Point(424, 380);
			this->labelDA->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelDA->Name = L"labelDA";
			this->labelDA->Size = System::Drawing::Size(0, 18);
			this->labelDA->TabIndex = 16;
			// 
			// NombreArchivo
			// 
			this->NombreArchivo->FileName = L"pokemons";
			this->NombreArchivo->Filter = L"(*.txt)|";
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HotTrack;
			this->ClientSize = System::Drawing::Size(666, 592);
			this->Controls->Add(this->labelDA);
			this->Controls->Add(this->textBoxT);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_PantallaPokedex);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MenuPrincipal";
			this->Text = L"MENU PRINCIPAL";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma endregion

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	ProcesarArchivo archivo = ProcesarArchivo();
	//Lectura del Archivo
	Ordenes.LeerArchivo("Pokemons.txt");
	std::string Mostrar = "";
	Mostrar = Ordenes.ImprimirPokemons();

	txt_PantallaPokedex->Text = gcnew String(Mostrar.c_str());
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	txt_PantallaPokedex->Text = "";
	textBoxT->Text = "";

	clock_t Tiempo;
	Tiempo = clock();

	ListadoPokemon* Info = Ordenes.Almacenar();
	int Contador = Ordenes.contador();

	Ordenes.SelectionSort(Info, Contador, 0);

	for (size_t i = 0; i < Contador; i++)
	{
		txt_PantallaPokedex->Text += Info[i].UnicNumber + ", ";
		txt_PantallaPokedex->Text += gcnew String(Info[i].NombreP.c_str());
		txt_PantallaPokedex->Text += ", " + Info[i].Generacion + "\r\n";
	}
	float StopWatch = 0;
	Tiempo = clock() - Tiempo;
	StopWatch = Tiempo;
	textBoxT->Text = "" + StopWatch + " ms";
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

	txt_PantallaPokedex->Text = "";
	textBoxT->Text = "";

	clock_t Tiempo;
	Tiempo = clock();

	ListadoPokemon* Info = Ordenes.Almacenar();
	int Contador = Ordenes.contador();

	Ordenes.ShellSort(Info, Contador, 0);

	for (size_t i = 0; i < Contador; i++)
	{
		txt_PantallaPokedex->Text += Info[i].UnicNumber + ", ";
		txt_PantallaPokedex->Text += gcnew String(Info[i].NombreP.c_str());
		txt_PantallaPokedex->Text += ", " + Info[i].Generacion + "\r\n";
	}
	float StopWatch = 0;
	Tiempo = clock() - Tiempo;
	StopWatch = Tiempo;
	textBoxT->Text = "" + StopWatch + " ms";
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	txt_PantallaPokedex->Text = "";
	textBoxT->Text = "";

	clock_t Tiempo;
	Tiempo = clock();

	ListadoPokemon* Info = Ordenes.Almacenar();
	int conteo = Ordenes.contador() - 1;
	Ordenes.startQuickSort(Info, 0, conteo);

	for (size_t i = 0; i < conteo + 1; i++)
	{
		txt_PantallaPokedex->Text += Info[i].UnicNumber + ", ";
		txt_PantallaPokedex->Text += gcnew String(Info[i].NombreP.c_str());
		txt_PantallaPokedex->Text += ", " + Info[i].Generacion + "\r\n";
	}
	float StopWatch = 0;
	Tiempo = clock() - Tiempo;
	StopWatch = Tiempo;
	textBoxT->Text = "" + StopWatch + " ms";
}
private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {


}
	};
}
