using ShatteredTextualEditor.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShatteredTextualEditor.ViewModel
{
    public class MainVM : NotificationObject
    {
        
        public MainVM()
        {

        }

        private string title;

        public string Title
        {
            get { return title; }
            set
            {
                title = value;
                OnPropertyChanged("Title");
            }
        }


        public ObservableCollection<Level> Levels { get; set; }

        private Level level;

        public Level SelectedLevel
        {
            get { return level; }
            set
            {
                level = value;
                OnPropertyChanged("SelectedLevel");
            }
        }

        private Choice choice;

        public Choice SelectedChoice
        {
            get { return choice; }
            set
            {
                choice = value;
                OnPropertyChanged("SelectedChoice");
            }
        }


        public ObservableCollection<string> ProgressionEvents { get; set; }

    }
}
