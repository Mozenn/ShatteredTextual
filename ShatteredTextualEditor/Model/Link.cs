using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShatteredTextualEditor.Model
{
    public enum Condition {None, Item, Event, Probability};
    public class Link : NotificationObject
    {
        private string nextLevel;

        public string NextLevel
        {
            get { return nextLevel; }
            set
            {
                nextLevel = value;
                OnPropertyChanged("NextLevel");
            }
        }

        private Condition conditionType;

        public Condition ConditionType
        {
            get { return conditionType; }
            set
            {
                conditionType = value;
                OnPropertyChanged("ConditionType");
            }
        }

        private string condition;

        public string Condition
        {
            get { return condition; }
            set
            {
                condition = value;
                OnPropertyChanged("Condition");
            }
        }

    }
}
