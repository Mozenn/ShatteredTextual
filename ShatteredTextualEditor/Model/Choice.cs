using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShatteredTextualEditor.Model
{

    public class Choice : NotificationObject
    {
        private string text;

        public string Text
        {
            get { return text; }
            set
            {
                text = value;
                OnPropertyChanged("Text");
            }
        }

        public ObservableCollection<Link> Links; 


    }
}
