using System.Xml;
using System.Xml.XPath;

namespace IS_Lab1_XML
{
    internal class XMLReadWithXLSTDOM
    {
        public static void Read(string filepath)
        {
            XPathDocument document = new XPathDocument(filepath);
            XPathNavigator navigator = document.CreateNavigator();
            XmlNamespaceManager manager = new
            XmlNamespaceManager(navigator.NameTable);
            manager.AddNamespace("x", "http://rejestrymedyczne.ezdrowie.gov.pl/rpl/eksport-danychv1.0");
            XPathExpression query = navigator.Compile("/x:produktyLecznicze/x:produktLeczniczy[@postac = 'Krem' and @nazwaPowszechnieStosowana = 'Mometasoni furoas']");
            query.SetContext(manager);
            int count = navigator.Select(query).Count;
            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas {0}", count);
        }

        public static void ReadAlt(string filepath)
        {
            XPathDocument document = new XPathDocument(filepath);
            XPathNavigator navigator = document.CreateNavigator();
            XmlNamespaceManager manager = new
            XmlNamespaceManager(navigator.NameTable);
            manager.AddNamespace("x", "http://rejestrymedyczne.ezdrowie.gov.pl/rpl/eksport-danychv1.0");
            XPathExpression query = navigator.Compile("/x:produktyLecznicze/x:produktLeczniczy");
            query.SetContext(manager);
            XPathNodeIterator iterator = navigator.Select(query);
            Dictionary<string, HashSet<string>> drugsDict = new Dictionary<string, HashSet<string>>();
            while (iterator.MoveNext())
            {
                string form = iterator.Current.GetAttribute("postac", "");
                string name = iterator.Current.GetAttribute("nazwaPowszechnieStosowana", "");
                if (!drugsDict.ContainsKey(name))
                {
                    drugsDict.Add(name, new HashSet<string>());
                }
                drugsDict[name].Add(form);
            }
            /*
            foreach (var drug in drugsDict)
            {
                Console.WriteLine("Produkt leczniczy: {0}", drug.Key);
                foreach (var form in drug.Value)
                {
                    Console.WriteLine("Postać: {0}", form);
                }
            }
            */

            int amount = 0;

            foreach (var pair in drugsDict)
            {
                if (pair.Value.Count > 1)
                {
                    amount++;
                }

            }

            Console.WriteLine("Ilość produktów leczniczych: {0}", drugsDict.Count);
            Console.WriteLine("Ilość różnych produktów leczniczych z różnymi formami: {0}", amount);

        }

        /*dodaj funkcję listowania trzech podmiotów produkujących najwięcej kremów,
podając nazwę podmiotu oraz liczbę produktów o postaci kremu – analogiczną
modyfikację dopisz do klasy XMLReadWithDOMApproach oraz
XMLReadWithSAXApproach*/
        public static void ReadTop3CreamProducers(string filepath)
        {
            XPathDocument document = new XPathDocument(filepath);
            XPathNavigator navigator = document.CreateNavigator();
            XmlNamespaceManager manager = new
            XmlNamespaceManager(navigator.NameTable);
            manager.AddNamespace("x", "http://rejestrymedyczne.ezdrowie.gov.pl/rpl/eksport-danychv1.0");
            XPathExpression query = navigator.Compile("/x:podmiotyRealizujaceDostep/x:podmiotRealizujacyDostep");
            query.SetContext(manager);
            XPathNodeIterator iterator = navigator.Select(query);
            Dictionary<string, int> producersDict = new Dictionary<string, int>();
            while (iterator.MoveNext())
            {
                string name = iterator.Current.GetAttribute("nazwaPodmiotu", "");
                XPathExpression query2 = iterator.Current.Compile("x:produktyLecznicze/x:produktLeczniczy[@postac = 'Krem']");
                query2.SetContext(manager);
                int count = iterator.Current.Select(query2).Count;
                if (!producersDict.ContainsKey(name))
                {
                    producersDict.Add(name, count);
                }
                else
                {
                    producersDict[name] += count;
                }
            }
            var sortedDict = from entry in producersDict orderby entry.Value descending select entry;
            int i = 0;
            foreach (var pair in sortedDict)
            {
                if (i < 3)
                {
                    Console.WriteLine("Nazwa podmiotu: {0}, Liczba kremów: {1}", pair.Key, pair.Value);
                    i++;
                }
                else
                {
                    break;
                }
            }
        }
    }
}
