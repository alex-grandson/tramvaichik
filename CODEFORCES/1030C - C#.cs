// C. Вася и золотой билет
// https://codeforces.com/contest/1030/problem/C

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problemC
{
    class Program
    {
        static void Main(string[] args)
        {
            int l = Convert.ToInt32(Console.ReadLine());
            string ticketRaw = Console.ReadLine();
            string ticket = "";
            for (int i = 0; i < ticketRaw.Length; i++)
            {
                if (ticketRaw[i] != '0')
                {
                    ticket += ticketRaw[i];
                }
            }
            int s0 = 0;
            bool solFound = false;
            for (int i = 0; i < ticket.Length - 1 && !solFound; i++)
            {
                s0 += Convert.ToInt32(ticket[i] - '0');
                int s1 = 0;
                int j = i;
                while (s1 <= s0 && j < ticket.Length - 1)
                {
                    s1 += Convert.ToInt32(ticket[j + 1] - '0');
                    if (s1 == s0 && j == ticket.Length - 2)
                    {
                        solFound = true; // Решение найдено
                        break;
                    }
                    else if (s1 == s0 && j < ticket.Length - 2)
                    {
                        s1 = 0;
                    }
                    j++;
                }
            }
            if (ticket.Length == 0)
            {
                solFound = true;
            }
            if (solFound)
            {
                Console.Write("YES");
            }
            else
            {
                Console.Write("NO");
            }
        }
    }
}