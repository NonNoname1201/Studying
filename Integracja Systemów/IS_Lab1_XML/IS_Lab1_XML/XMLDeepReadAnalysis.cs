using System.Xml;


namespace IS_Lab1_XML
{
    internal class XMLDeepReadAnalysis
    {
        /*Zadanie 1.5. [zaawansowane] Głębsza analiza treści dokumentu
Przy pomocy poznanych technik i narzędzi wydobądź i przeprowadź zaawansowaną
analizę treści dokumentu XML.
• Rozbuduj przygotowaną aplikację w taki sposób, aby możliwe było identyfikowanie
produktów leczniczych zawierających jedną lub kilka substancji czynnych.
• Stwórz słownik wartości wyróżniających wszystkie produkty lecznicze a następnie
przygotuj graficzne narzędzie do wizualizacji statystyk dotyczących wystąpień
produktów leczniczych spełniających zdefiniowane kryteria.*/

        public static void Read(string filepath)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(filepath);

            Dictionary<string, int> drugsDict = new Dictionary<string, int>();
            var drugs = doc.GetElementsByTagName("produktLeczniczy");
            foreach (XmlNode d in drugs)
            {
                string name = d.Attributes.GetNamedItem("nazwaProduktu").Value;
                XmlNodeList nodes = d.ChildNodes;

                int amount = 0;
                foreach (XmlElement node in nodes)
                {
                    if (node.Name == "substancjeCzynne")
                    {
                        amount = node.ChildNodes.Count;
                    }
                }

                if (!drugsDict.ContainsKey(name))
                {
                    drugsDict[name] = amount;
                }
                else
                {
                    drugsDict[name] += amount;
                }
            }

            foreach (var pair in drugsDict)
            {
                Console.WriteLine("Nazwa produktu: {0}, Liczba różnych substancji: {1}", pair.Key, pair.Value);
            }

            Console.WriteLine("Wizualizacja:");
            //TODO: Wizualizacja
        }
    }
}
