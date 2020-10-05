// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=200
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoomProblem
{
    class Program
    {
        // https://informatics.msk.ru/mod/statements/view3.php?id=268&chapterid=200
        
        static void Nei(int x, int y, char[,] a, int size)
        {
            if (y - 1 > 0 && a[x, y - 1] == '.')
            {
                a[x, y - 1] = '+';
                //Out(a, size);
                Nei(x, y - 1, a, size);
            }
            if (x + 1 < size && a[x + 1, y] == '.')
            {
                a[x + 1, y] = '+';
                //Out(a, size);
                Nei(x + 1, y, a, size);
            }
            if (y + 1 < size && a[x, y + 1] == '.')
            {
                a[x, y + 1] = '+';
                //Out(a, size);
                Nei(x, y + 1, a, size);
            }
            if (x - 1 > 0 && a[x - 1, y] == '.')
            {
                a[x - 1, y] = '+';
                //Out(a, size);
                Nei(x - 1, y, a, size);
            } 
            if (a[x, y] == '.')
            {
                a[x, y] = '+';
                //Out(a, size);
                Nei(x, y, a, size);
            }
        }
        static void Main(string[] args)
        {
            int size = Convert.ToInt32(Console.ReadLine());
            char[,] floor = new char[10, 10];
            for (int i = 0; i < size; i++)
            {
                string a = Console.ReadLine();
                for (int j = 0; j < size; j++)
                    floor[i, j] = Convert.ToChar(a[j]);
            }
            string s = Console.ReadLine();
            int x = Convert.ToInt32(s.Split()[0]) - 1;
            int y = Convert.ToInt32(s.Split()[1]) - 1;

            Nei(x, y, floor, size);

            int count = 0;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (floor[i, j] == '+')
                        count += 1;

            Console.Write(count);
            //Console.ReadKey();
        }

        // Разноцветный вывод
        static void Out(char[,] a, int size)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (a[i, j] == '+')
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write(a[i, j]);
                        Console.ResetColor();
                    }
                    else Console.Write(a[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine("-------------");
        }
    }
}
