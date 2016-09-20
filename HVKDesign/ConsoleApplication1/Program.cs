using System;
using System.Collections.Generic;
using System.Text;
using AdoDbApi;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            bool stat = true;
            CADORecord rec = new CADORecord();
            CADORecord.OpenConnection();
            rec.Open("select * from building");
            if(!rec.EOF()) 
			    rec.MoveFirst();
            if(rec.EOF() && rec.BOF())
                stat = false;
		    if(stat)
			    do
			    {
                    string str = rec.FieldData("ID").ToString() + " - " + rec.FieldData("Name").ToString();
                    System.Console.WriteLine(str);
                    System.Console.ReadKey();
					rec.MoveNext();
			    }while(!rec.EOF());
		    rec.Close();
        }
    }
}
