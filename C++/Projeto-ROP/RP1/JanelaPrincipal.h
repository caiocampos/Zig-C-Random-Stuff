#pragma once

namespace RP1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for JanelaPrincipal
	/// </summary>
	public ref class JanelaPrincipal : public System::Windows::Forms::Form
	{
	public:
		JanelaPrincipal(void)
		{
			InitializeComponent();
			tabela->Rows[0]->Cells[1]->Value = "0";
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~JanelaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::VScrollBar^  barraLateral;
	private: System::Windows::Forms::DataGridView^  tabela;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  grafico;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nome;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  valores;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->grafico = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->barraLateral = (gcnew System::Windows::Forms::VScrollBar());
			this->tabela = (gcnew System::Windows::Forms::DataGridView());
			this->nome = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->valores = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grafico))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tabela))->BeginInit();
			this->SuspendLayout();
			// 
			// grafico
			// 
			this->grafico->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->grafico->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->grafico->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::TopBottom;
			this->grafico->BorderlineColor = System::Drawing::Color::Black;
			chartArea1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			chartArea1->Name = L"areaGrafico";
			this->grafico->ChartAreas->Add(chartArea1);
			this->grafico->Location = System::Drawing::Point(306, 12);
			this->grafico->Name = L"grafico";
			this->grafico->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Excel;
			series1->ChartArea = L"areaGrafico";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar;
			series1->Name = L"series";
			this->grafico->Series->Add(series1);
			this->grafico->Size = System::Drawing::Size(360, 520);
			this->grafico->TabIndex = 2;
			this->grafico->Text = L"gráfico";
			// 
			// barraLateral
			// 
			this->barraLateral->Dock = System::Windows::Forms::DockStyle::Right;
			this->barraLateral->Location = System::Drawing::Point(669, 0);
			this->barraLateral->Name = L"barraLateral";
			this->barraLateral->Size = System::Drawing::Size(19, 362);
			this->barraLateral->TabIndex = 0;
			this->barraLateral->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &JanelaPrincipal::barraLateral_Scroll);
			// 
			// tabela
			// 
			this->tabela->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->tabela->BackgroundColor = System::Drawing::Color::CadetBlue;
			this->tabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tabela->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->nome, this->valores});
			this->tabela->GridColor = System::Drawing::Color::Black;
			this->tabela->Location = System::Drawing::Point(12, 12);
			this->tabela->Name = L"tabela";
			this->tabela->Size = System::Drawing::Size(288, 520);
			this->tabela->TabIndex = 1;
			this->tabela->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &JanelaPrincipal::tabela_CellValueChanged);
			this->tabela->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &JanelaPrincipal::tabela_RowsAdded);
			this->tabela->UserDeletedRow += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &JanelaPrincipal::tabela_UserDeletedRow);
			// 
			// nome
			// 
			this->nome->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->nome->HeaderText = L"Nome";
			this->nome->Name = L"nome";
			// 
			// valores
			// 
			this->valores->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->valores->HeaderText = L"Valores";
			this->valores->Name = L"valores";
			// 
			// JanelaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(688, 362);
			this->Controls->Add(this->grafico);
			this->Controls->Add(this->tabela);
			this->Controls->Add(this->barraLateral);
			this->Name = L"JanelaPrincipal";
			this->Text = L"JanelaPrincipal";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->grafico))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tabela))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void JanelaPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
				 }
		private: System::Void barraLateral_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
					 int pos = e->NewValue - e->OldValue;
					 System::Drawing::Point pGrafico =  this->grafico->Location;
					 System::Drawing::Point pTabela = this->tabela->Location;
					 pGrafico.Y += 2 * -pos;
					 pTabela.Y += 2 * -pos;
					 this->grafico->Location = pGrafico;
					 this->tabela->Location = pTabela;
				 }
		private: System::Void tabela_UserDeletedRow(System::Object^  sender, System::Windows::Forms::DataGridViewRowEventArgs^  e) {
					 desenhaGrafico();
				 }
		private: System::Void tabela_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
					 if(e->ColumnIndex == 1) {
						 int ri = e->RowIndex;
						 if(ri < 0) return;
						 try {
							 Convert::ToDouble((String^)tabela->Rows[ri]->Cells[1]->Value);
						 } catch (Exception^ ex) {
							 tabela->Rows[ri]->Cells[1]->Value = "0";
							 MessageBox::Show("Conversão Inlegal\nEste valor deve ser Numérico", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
						 }
					 }
					 desenhaGrafico();
				 }
		private: System::Void tabela_RowsAdded(System::Object^  sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^  e) {
					 tabela->Rows[e->RowIndex]->Cells[1]->Value = "0";
				 }
		private: System::Void desenhaGrafico() {
					 int i,corVermelho = 100,corVerde = 0,corAzul = 0;
					 this->grafico->Series->FindByName("series")->Points->Clear();
					 for(i = 0; i < tabela->RowCount; i++) {
						 Double val = Convert::ToDouble((String^)tabela->Rows[i]->Cells[1]->Value);
						 DataVisualization::Charting::DataPoint^  dataPoint1 = (gcnew DataVisualization::Charting::DataPoint(0, val));
						 dataPoint1->Color = System::Drawing::Color::FromArgb(corVermelho, corVerde, corAzul);
						 dataPoint1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
						 dataPoint1->Label = (String^)tabela->Rows[i]->Cells[0]->Value;
						 dataPoint1->LabelBackColor = System::Drawing::Color::White;
						 dataPoint1->LabelBorderWidth = 0;
						 this->grafico->Series->FindByName("series")->Points->Add(dataPoint1);
						 corVermelho = (corVermelho + 200) % 255;
						 corVerde = (corVerde + 75) % 255;
						 corAzul = (corAzul + 150) % 255;
					 }
				 }
	};
}
