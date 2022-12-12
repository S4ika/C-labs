using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FilmographyDB
{
    public partial class Filmography : Form
    {
        public Filmography()
        {
            InitializeComponent();
        }

        public System.Data.SqlClient.SqlConnection connect;
        public void Filmography_Load(object sender, EventArgs e)
        {
            String connectionString = "Data Source=DESKTOP-T77QNB9\\SQLEXPRESS;Initial Catalog=SQL_Filmography;Integrated Security=True";
            connect = new System.Data.SqlClient.SqlConnection(connectionString);
            connect.Open();
        }

        private void фильмыToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Movies movies = new Movies();
            movies.Show();
        }

        private void записиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Note note = new Note();
            note.Show();
        }

        private void журналВыдачиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            IssueLog issueLog = new IssueLog();
            issueLog.Show();
        }

        private void клиентыToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clientele clientele = new Clientele();
            clientele.Show();
        }

        private void библиотекариToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Librarians librarians = new Librarians();
            librarians.Show();
        }

        private void оПрограммеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Description descr = new Description();
            descr.Show();
        }

        private void zhurnalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Zhurnal zh = new Zhurnal();
            zh.Show();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            int a = 6;
        }
    }
}
