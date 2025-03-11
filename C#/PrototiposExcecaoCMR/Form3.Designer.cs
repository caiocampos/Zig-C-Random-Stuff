namespace WindowsFormsApplication1
{
    partial class Form3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.txtDataInicial = new System.Windows.Forms.TextBox();
            this.lblDF = new System.Windows.Forms.Label();
            this.lblDI = new System.Windows.Forms.Label();
            this.txtDataFinal = new System.Windows.Forms.TextBox();
            this.txtPerc = new System.Windows.Forms.TextBox();
            this.lblPerc = new System.Windows.Forms.Label();
            this.btnSalvar = new System.Windows.Forms.Button();
            this.dgvProdutos = new System.Windows.Forms.DataGridView();
            this.dcolProduto = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dcolExcluir = new System.Windows.Forms.DataGridViewButtonColumn();
            this.btnIncluir = new System.Windows.Forms.Button();
            this.lblNomeProduto = new System.Windows.Forms.Label();
            this.txtProduto = new System.Windows.Forms.TextBox();
            this.lblProduto = new System.Windows.Forms.Label();
            this.cboCategoria = new System.Windows.Forms.ComboBox();
            this.lblTipo = new System.Windows.Forms.Label();
            this.lblPeriodo = new System.Windows.Forms.Label();
            this.cboPeriodo = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.dgvProdutos)).BeginInit();
            this.SuspendLayout();
            // 
            // txtDataInicial
            // 
            this.txtDataInicial.Location = new System.Drawing.Point(291, 70);
            this.txtDataInicial.Name = "txtDataInicial";
            this.txtDataInicial.Size = new System.Drawing.Size(100, 22);
            this.txtDataInicial.TabIndex = 6;
            // 
            // lblDF
            // 
            this.lblDF.AutoSize = true;
            this.lblDF.Location = new System.Drawing.Point(397, 73);
            this.lblDF.Name = "lblDF";
            this.lblDF.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.lblDF.Size = new System.Drawing.Size(76, 17);
            this.lblDF.TabIndex = 7;
            this.lblDF.Text = "Data Final:";
            // 
            // lblDI
            // 
            this.lblDI.AutoSize = true;
            this.lblDI.Location = new System.Drawing.Point(204, 73);
            this.lblDI.Name = "lblDI";
            this.lblDI.Size = new System.Drawing.Size(81, 17);
            this.lblDI.TabIndex = 5;
            this.lblDI.Text = "Data Inicial:";
            // 
            // txtDataFinal
            // 
            this.txtDataFinal.Location = new System.Drawing.Point(479, 70);
            this.txtDataFinal.Name = "txtDataFinal";
            this.txtDataFinal.Size = new System.Drawing.Size(100, 22);
            this.txtDataFinal.TabIndex = 8;
            // 
            // txtPerc
            // 
            this.txtPerc.Location = new System.Drawing.Point(98, 70);
            this.txtPerc.Name = "txtPerc";
            this.txtPerc.Size = new System.Drawing.Size(100, 22);
            this.txtPerc.TabIndex = 4;
            // 
            // lblPerc
            // 
            this.lblPerc.AutoSize = true;
            this.lblPerc.Location = new System.Drawing.Point(12, 73);
            this.lblPerc.Name = "lblPerc";
            this.lblPerc.Size = new System.Drawing.Size(80, 17);
            this.lblPerc.TabIndex = 0;
            this.lblPerc.Text = "Percentual:";
            // 
            // btnSalvar
            // 
            this.btnSalvar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnSalvar.Location = new System.Drawing.Point(12, 340);
            this.btnSalvar.Name = "btnSalvar";
            this.btnSalvar.Size = new System.Drawing.Size(75, 23);
            this.btnSalvar.TabIndex = 9;
            this.btnSalvar.Text = "Salvar";
            this.btnSalvar.UseVisualStyleBackColor = true;
            // 
            // dgvProdutos
            // 
            this.dgvProdutos.AllowUserToAddRows = false;
            this.dgvProdutos.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvProdutos.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dgvProdutos.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvProdutos.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dcolProduto,
            this.dcolExcluir});
            this.dgvProdutos.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.dgvProdutos.GridColor = System.Drawing.SystemColors.Control;
            this.dgvProdutos.Location = new System.Drawing.Point(12, 157);
            this.dgvProdutos.Name = "dgvProdutos";
            this.dgvProdutos.RowTemplate.Height = 24;
            this.dgvProdutos.Size = new System.Drawing.Size(587, 177);
            this.dgvProdutos.TabIndex = 8;
            // 
            // dcolProduto
            // 
            this.dcolProduto.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.dcolProduto.HeaderText = "Produto";
            this.dcolProduto.Name = "dcolProduto";
            // 
            // dcolExcluir
            // 
            this.dcolExcluir.HeaderText = "Excluir";
            this.dcolExcluir.Name = "dcolExcluir";
            this.dcolExcluir.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dcolExcluir.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            this.dcolExcluir.Text = "Excluir";
            // 
            // btnIncluir
            // 
            this.btnIncluir.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnIncluir.Location = new System.Drawing.Point(524, 128);
            this.btnIncluir.Name = "btnIncluir";
            this.btnIncluir.Size = new System.Drawing.Size(75, 23);
            this.btnIncluir.TabIndex = 7;
            this.btnIncluir.Text = "Incluir";
            this.btnIncluir.UseVisualStyleBackColor = true;
            // 
            // lblNomeProduto
            // 
            this.lblNomeProduto.AutoSize = true;
            this.lblNomeProduto.Location = new System.Drawing.Point(186, 45);
            this.lblNomeProduto.Name = "lblNomeProduto";
            this.lblNomeProduto.Size = new System.Drawing.Size(109, 17);
            this.lblNomeProduto.TabIndex = 6;
            this.lblNomeProduto.Text = "lblNomeProduto";
            // 
            // txtProduto
            // 
            this.txtProduto.Location = new System.Drawing.Point(80, 42);
            this.txtProduto.Name = "txtProduto";
            this.txtProduto.Size = new System.Drawing.Size(100, 22);
            this.txtProduto.TabIndex = 5;
            // 
            // lblProduto
            // 
            this.lblProduto.AutoSize = true;
            this.lblProduto.Location = new System.Drawing.Point(12, 45);
            this.lblProduto.Name = "lblProduto";
            this.lblProduto.Size = new System.Drawing.Size(62, 17);
            this.lblProduto.TabIndex = 4;
            this.lblProduto.Text = "Produto:";
            // 
            // cboCategoria
            // 
            this.cboCategoria.FormattingEnabled = true;
            this.cboCategoria.Items.AddRange(new object[] {
            "Garantia Extendida",
            "Seguro Roubo e Furto + Quebra",
            "Seguro Roubo e Furto"});
            this.cboCategoria.Location = new System.Drawing.Point(58, 12);
            this.cboCategoria.Name = "cboCategoria";
            this.cboCategoria.Size = new System.Drawing.Size(333, 24);
            this.cboCategoria.TabIndex = 16;
            this.cboCategoria.Text = "Seguro Roubo e Furto";
            this.cboCategoria.TextChanged += new System.EventHandler(this.cboCategoria_TextChanged);
            // 
            // lblTipo
            // 
            this.lblTipo.AutoSize = true;
            this.lblTipo.Location = new System.Drawing.Point(12, 15);
            this.lblTipo.Name = "lblTipo";
            this.lblTipo.Size = new System.Drawing.Size(40, 17);
            this.lblTipo.TabIndex = 15;
            this.lblTipo.Text = "Tipo:";
            // 
            // lblPeriodo
            // 
            this.lblPeriodo.AutoSize = true;
            this.lblPeriodo.Location = new System.Drawing.Point(12, 101);
            this.lblPeriodo.Name = "lblPeriodo";
            this.lblPeriodo.Size = new System.Drawing.Size(61, 17);
            this.lblPeriodo.TabIndex = 17;
            this.lblPeriodo.Text = "Período:";
            this.lblPeriodo.Visible = false;
            // 
            // cboPeriodo
            // 
            this.cboPeriodo.FormattingEnabled = true;
            this.cboPeriodo.Items.AddRange(new object[] {
            "12",
            "24"});
            this.cboPeriodo.Location = new System.Drawing.Point(79, 98);
            this.cboPeriodo.Name = "cboPeriodo";
            this.cboPeriodo.Size = new System.Drawing.Size(121, 24);
            this.cboPeriodo.TabIndex = 18;
            this.cboPeriodo.Text = "12";
            this.cboPeriodo.Visible = false;
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(611, 375);
            this.Controls.Add(this.btnSalvar);
            this.Controls.Add(this.cboPeriodo);
            this.Controls.Add(this.dgvProdutos);
            this.Controls.Add(this.lblPeriodo);
            this.Controls.Add(this.cboCategoria);
            this.Controls.Add(this.lblTipo);
            this.Controls.Add(this.btnIncluir);
            this.Controls.Add(this.lblNomeProduto);
            this.Controls.Add(this.lblPerc);
            this.Controls.Add(this.txtProduto);
            this.Controls.Add(this.lblProduto);
            this.Controls.Add(this.txtPerc);
            this.Controls.Add(this.txtDataInicial);
            this.Controls.Add(this.txtDataFinal);
            this.Controls.Add(this.lblDF);
            this.Controls.Add(this.lblDI);
            this.Name = "Form3";
            this.Text = "Form3";
            ((System.ComponentModel.ISupportInitialize)(this.dgvProdutos)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtDataInicial;
        private System.Windows.Forms.Label lblDF;
        private System.Windows.Forms.Label lblDI;
        private System.Windows.Forms.TextBox txtDataFinal;
        private System.Windows.Forms.TextBox txtPerc;
        private System.Windows.Forms.Label lblPerc;
        private System.Windows.Forms.Button btnIncluir;
        private System.Windows.Forms.Label lblNomeProduto;
        private System.Windows.Forms.TextBox txtProduto;
        private System.Windows.Forms.Label lblProduto;
        private System.Windows.Forms.DataGridView dgvProdutos;
        private System.Windows.Forms.Button btnSalvar;
        private System.Windows.Forms.DataGridViewTextBoxColumn dcolProduto;
        private System.Windows.Forms.DataGridViewButtonColumn dcolExcluir;
        private System.Windows.Forms.ComboBox cboCategoria;
        private System.Windows.Forms.Label lblTipo;
        private System.Windows.Forms.Label lblPeriodo;
        private System.Windows.Forms.ComboBox cboPeriodo;
    }
}

