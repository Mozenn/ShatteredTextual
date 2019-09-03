using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShatteredTextualEditor.Model
{
    public class Level
    {
        private string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private string description;

        public string Description
        {
            get { return description; }
            set { description = value; }
        }

        public List<Choice> Choices { get; set; }


    }

    public class Choice
    {
        private string text;

        public string Text
        {
            get { return text; }
            set { text = value; }
        }

        private string link;

        public string Link
        {
            get { return link; }
            set { link = value; }
        }


    }
}
