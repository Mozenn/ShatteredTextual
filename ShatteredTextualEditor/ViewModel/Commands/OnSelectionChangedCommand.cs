using ShatteredTextualEditor.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace ShatteredTextualEditor.ViewModel.Commands
{
    public class OnSelectionChangedCommand : ICommand
    {
        public MainVM VM { get; set; }

        public event EventHandler CanExecuteChanged;


        public OnSelectionChangedCommand(MainVM vm)
        {
            VM = vm; 
        }
        public bool CanExecute(object parameter)
        {
            return true; 
        }

        public void Execute(object parameter)
        {
            var Tv = parameter as Level; 
            if(Tv != null)
            {
                Console.WriteLine("Hello World!!");
            }
        }
    }
}
