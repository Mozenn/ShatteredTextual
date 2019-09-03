using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShatteredTextualEditor.Model
{
    public class Game
    {

        private string title;

        public string Title
        {
            get { return title; }
            set { title = value; }
        }


        public List<Level> Levels { get; set; }

        public List<string> ProgressionEvents { get; set; }

    }
}
