using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();

            int rowIndex = 0;

            rowIndex = dgvProdutos.Rows.Add(new DataGridViewButtonCell());
            dgvProdutos.Rows[rowIndex].Cells["dcolProduto"].Value = string.Empty;
            dgvProdutos.Rows[rowIndex].Cells["dcolExcluir"].Value = "Excluir";
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
