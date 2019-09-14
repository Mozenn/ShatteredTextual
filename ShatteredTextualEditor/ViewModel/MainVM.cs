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
        // TODO : divide MainVM into LevelsVM & GameSettingsVM
        
        public MainVM()
        {
            Levels = new ObservableCollection<Level>();

            var L1 = new Level()
            {
                Name = "Hey",
                Description = "This is a description",
                Choices = new ObservableCollection<Choice>(),
                UnlockedItems = new ObservableCollection<string>(),
                UnlockedProgressionEvents = new ObservableCollection<string>()
            };

            var L2 = new Level()
            {
                Name = "Ho",
                Description = "This is not a description",
                Choices = new ObservableCollection<Choice>(),
                UnlockedItems = new ObservableCollection<string>(),
                UnlockedProgressionEvents = new ObservableCollection<string>()
            };

            var C1 = new Choice()
            {
                Text = "Choice1",
                Links = new ObservableCollection<Link>()
            };

            var C2 = new Choice()
            {
                Text = "Choice2",
                Links = new ObservableCollection<Link>()
            };

            var Lk1 = new Link()
            {
                NextLevel = "?",
                ConditionType = Condition.Item,
                Condition = "Axe"
            };

            var Lk2 = new Link()
            {
                NextLevel = "?",
                ConditionType = Condition.Event,
                Condition = "Part1"
            };

            C1.Links.Add(Lk1);
            C1.Links.Add(Lk2);

            C2.Links.Add(Lk1);

            L1.Choices.Add(C1);
            L1.Choices.Add(C2);
            L1.UnlockedItems.Add("Axe");
            L1.UnlockedProgressionEvents.Add("End");

            L2.Choices.Add(C1);
            L2.UnlockedItems.Add("hapiness");
            L2.UnlockedProgressionEvents.Add("death");

            Levels.Add(L1);
            Levels.Add(L2);

            ProgressionEvents = new ObservableCollection<string>();
            ProgressionEvents.Add("Hey");
            ProgressionEvents.Add("Ho");

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

        private string selectedItem;

        public string SelectedItem
        {
            get { return selectedItem; }
            set { selectedItem = value; }
        }

        private string selectedUnlockedEvent;

        public string SelectedUnlockedEvent
        {
            get { return selectedUnlockedEvent; }
            set { selectedUnlockedEvent = value; }
        }

        // List of all values of Condition enum to bind to ComboBox of Links  
        public static IList<Condition> Conditions
        {
            get
            {
                return Enum.GetValues(typeof(Condition)).Cast<Condition>().ToList<Condition>();
            }
        }



        public void UpdateLevels()
        {

        }

        // GAME SETTINGS 

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

        private string startLevel;

        public string StartLevel
        {
            get { return startLevel; }
            set { startLevel = value; }
        }


        public ObservableCollection<string> ProgressionEvents { get; set; }

        private string selectedEvent;

        public string SelectedEvent
        {
            get { return selectedEvent; }
            set { selectedEvent = value; }
        }


        #region Commands

        #endregion // Commands 

    }
}
