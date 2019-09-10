using ShatteredTextualEditor.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShatteredTextualEditor.ViewModel
{
    public class LevelVM : NotificationObject
    {

        public LevelVM()
        {

        }

        // LEVELS 

        ObservableCollection<Level> Levels;

        private async void LoadLevels()
        {
            // TODO 
        }
    }
}
