#pragma once
#include "MundoIAvsPCService.h"

namespace Mundo1Kevin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMundo11
	/// </summary>
	public ref class FrmMundo11 : public System::Windows::Forms::Form
	{
	public:
		FrmMundo11(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			service = new MundoIAvsPCService(pnlDibujo->Width, pnlDibujo->Height, 3);//3 vidas
			//Cargamos el fondo
			char rutaFondo[] = "piso1.jpg";
			service->cargarFondo(rutaFondo);
			//Cargamos a alfredo
			char rutaAlfredo[] = "alfredoPeruano2.png";
			service->cargarSpriteAlfredo(rutaAlfredo, 4, 4);
			teclaPresionadaAlfredo = Direccion::Ninguno;

			//dibujar al unico aliado q tengo xd
			service->generarAliado(1);
			service->generarEnemigos(2);
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmMundo11()
		{
			if (components)
			{
				delete components;
			}
			if (service) delete service;

		}
	private: System::Windows::Forms::Panel^ pnlDibujo;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		//mis propios elementos
		MundoIAvsPCService* service;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblDialogo;


		   Direccion teclaPresionadaAlfredo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMundo11::typeid));
			this->pnlDibujo = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblDialogo = (gcnew System::Windows::Forms::Label());
			this->pnlDibujo->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlDibujo
			// 
			this->pnlDibujo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlDibujo.BackgroundImage")));
			this->pnlDibujo->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pnlDibujo->Controls->Add(this->lblDialogo);
			this->pnlDibujo->Location = System::Drawing::Point(1, 3);
			this->pnlDibujo->Name = L"pnlDibujo";
			this->pnlDibujo->Size = System::Drawing::Size(1026, 1046);
			this->pnlDibujo->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMundo11::timer1_Tick);
			// 
			// lblDialogo
			// 
			this->lblDialogo->BackColor = System::Drawing::Color::Black;
			this->lblDialogo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDialogo->ForeColor = System::Drawing::Color::White;
			this->lblDialogo->Location = System::Drawing::Point(0, 642);
			this->lblDialogo->Name = L"lblDialogo";
			this->lblDialogo->Size = System::Drawing::Size(1021, 135);
			this->lblDialogo->TabIndex = 5;
			this->lblDialogo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblDialogo->Visible = false;
			// 
			// FrmMundo11
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1027, 1061);
			this->Controls->Add(this->pnlDibujo);
			this->Name = L"FrmMundo11";
			this->Load += gcnew System::EventHandler(this, &FrmMundo11::FrmMundo11_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundo11::FrmMundo11_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMundo11::FrmMundo11_KeyUp);
			this->pnlDibujo->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmMundo11_Load(System::Object^ sender, System::EventArgs^ e) {
		//inicio el timer
		timer1->Start();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (service->estaEnPausa()) {
			String^ textoDialogo = "";
			bool dialogoContinua = service->actualizarDialogo(textoDialogo);
			lblDialogo->Text = textoDialogo;
			lblDialogo->Visible = true;

			if (!dialogoContinua) {
				lblDialogo->Visible = false;
			}
		}
		//mover enemigos
		service->moverEnemigos();
		//colision Aliado
		Aliado* aliadoColisionado = service->verificarColisionesAlfredoAliado();
		if (aliadoColisionado != nullptr) {
			int capturados = 0;
			service->iniciarDialogo(aliadoColisionado, capturados);
			return;
		}
		//moverlo :v
		if (teclaPresionadaAlfredo != Direccion::Ninguno) {
			service->moverAlfredo(teclaPresionadaAlfredo);
		}

		//RENDERIZADO
		Graphics^ canvas = pnlDibujo->CreateGraphics();
		BufferedGraphicsContext^ espacio_buffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio_buffer->Allocate(canvas, pnlDibujo->ClientRectangle);

		service->dibujarTodo(buffer->Graphics);
		buffer->Render(canvas);

		delete buffer;
		delete canvas;
	}
	private: System::Void FrmMundo11_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//MOVIMIENTO DE ALFREDO
		if (e->KeyCode == Keys::W) {
			teclaPresionadaAlfredo = Direccion::Arriba;
		}
		else if (e->KeyCode == Keys::S) {
			teclaPresionadaAlfredo = Direccion::Abajo;
		}
		else if (e->KeyCode == Keys::A) {
			teclaPresionadaAlfredo = Direccion::Izquierda;
		}
		else if (e->KeyCode == Keys::D) {
			teclaPresionadaAlfredo = Direccion::Derecha;
		}
	}
	private: System::Void FrmMundo11_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W || e->KeyCode == Keys::S ||
			e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
			teclaPresionadaAlfredo = Direccion::Ninguno;
		}
	}



};
}
