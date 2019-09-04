using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShatteredTextualEditor.ViewModel
{
    public class GameSettingsVM : INotifyPropertyChanged
    {

        // TODO : add delete, add & edit features 

        public GameSettingsVM()
        {
            ProgressionEvents = new ObservableCollection<string>();

            // TODO : Initialize ProgressionEvents & SelectedProgEvent 
        }

        // ------------- INOTIFYPROPERTYCHANGED INTERFACE 
        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
        }

        // -------------- PROGRESSION EVENTS 
        public ObservableCollection<string> ProgressionEvents { get; set; }

        private string selectedProgressionEvent;

        public event EventHandler SelecteProgressionEventChanged;

        public string SelecteProgressionEvent
        {
            get { return selectedProgressionEvent; }
            set
            {
                selectedProgressionEvent = value;
                SelecteProgressionEventChanged(this, new EventArgs());
                OnPropertyChanged("SelecteProgressionEvent");
            }
        }

    }
}
