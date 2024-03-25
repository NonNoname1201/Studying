using System.Xml;

namespace IS_Lab1_XML
{
    internal class XMLReadWithSSAXApproach
    {
        public static void Read(string filepath)
        {
            // konfiguracja początkowa dla XmlReadera
            XmlReaderSettings settings = new XmlReaderSettings();
            settings.IgnoreComments = true;
            settings.IgnoreProcessingInstructions = true;
            settings.IgnoreWhitespace = true;
            // odczyt zawartości dokumentu
            XmlReader reader = XmlReader.Create(filepath, settings);
            // zmienne pomocnicze
            int count = 0;
            string postac = "";
            string sc = "";
            reader.MoveToContent();
            // analiza każdego z węzłów dokumentu
            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name
                == "produktLeczniczy")
                {
                    postac = reader.GetAttribute("postac");
                    sc =
                    reader.GetAttribute("nazwaPowszechnieStosowana");
                    if (postac == "Krem" && sc == "Mometasoni furoas")
                        count++;
                }
            }
            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas {0}", count);
        }

        public static void ReadAlt(string filepath)
        {
            // konfiguracja początkowa dla XmlReadera
            XmlReaderSettings settings = new XmlReaderSettings();
            settings.IgnoreComments = true;
            settings.IgnoreProcessingInstructions = true;
            settings.IgnoreWhitespace = true;
            // odczyt zawartości dokumentu
            XmlReader reader = XmlReader.Create(filepath, settings);
            // zmienne pomocnicze
            string form = "";
            string name = "";
            Dictionary<string, HashSet<string>> drugsDict = new Dictionary<string, HashSet<string>>();
            reader.MoveToContent();
            // analiza każdego z węzłów dokumentu
            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name
                == "produktLeczniczy")
                {
                    form = reader.GetAttribute("postac");
                    name =
                    reader.GetAttribute("nazwaPowszechnieStosowana");
                    if (!drugsDict.ContainsKey(name))
                    {
                        drugsDict[name] = new HashSet<string>();
                    }
                    drugsDict[name].Add(form);
                }
            }
            /*
            foreach (var pair in drugsDict)
            {
                Console.WriteLine("Nazwa produktu: {0}, Liczba różnych form: {1}", pair.Key, pair.Value.Count);
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

        public static void ReadWhoMore(string filepath)
        {
            XmlReaderSettings settings = new XmlReaderSettings();
            settings.IgnoreComments = true;
            settings.IgnoreProcessingInstructions = true;
            settings.IgnoreWhitespace = true;
            XmlReader reader = XmlReader.Create(filepath, settings);
            reader.MoveToContent();

            Dictionary<string, int> creamProducers = new Dictionary<string, int>();
            Dictionary<string, int> tabletProducers = new Dictionary<string, int>();

            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name == "produktLeczniczy")
                {
                    string producer = reader.GetAttribute("podmiotOdpowiedzialny");
                    string form = reader.GetAttribute("postac");

                    if (form == "Krem")
                    {
                        if (!creamProducers.ContainsKey(producer))
                        {
                            creamProducers[producer] = 1;
                        }
                        else
                        {
                            creamProducers[producer]++;
                        }
                    }
                    else if (form == "Tabletka")
                    {
                        if (!tabletProducers.ContainsKey(producer))
                        {
                            tabletProducers[producer] = 1;
                        }
                        else
                        {
                            tabletProducers[producer]++;
                        }
                    }
                }
            }

            string mostCreams = creamProducers.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
            int maxCreams = creamProducers.Aggregate((l, r) => l.Value > r.Value ? l : r).Value;
            string mostTablets = tabletProducers.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
            int maxTablets = tabletProducers.Aggregate((l, r) => l.Value > r.Value ? l : r).Value;

            Console.WriteLine("The producer with the most creams is: {0}, with {1} creams", mostCreams, maxCreams);
            Console.WriteLine("The producer with the most tablets is: {0}, with {1} tablets", mostTablets, maxTablets);

        }

        public static void ReadTop3CreamProducers(string filepath){
            XmlReaderSettings settings = new XmlReaderSettings();
            settings.IgnoreComments = true;
            settings.IgnoreProcessingInstructions = true;
            settings.IgnoreWhitespace = true;
            XmlReader reader = XmlReader.Create(filepath, settings);
            reader.MoveToContent();

            Dictionary<string, int> creamProducers = new Dictionary<string, int>();

            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name == "produktLeczniczy")
                {
                    string producer = reader.GetAttribute("podmiotOdpowiedzialny");
                    string form = reader.GetAttribute("postac");

                    if (form == "Krem")
                    {
                        if (!creamProducers.ContainsKey(producer))
                        {
                            creamProducers[producer] = 1;
                        }
                        else
                        {
                            creamProducers[producer]++;
                        }
                    }
                }
            }

            var top3CreamProducers = creamProducers.OrderByDescending(x => x.Value).Take(3);
            foreach (var producer in top3CreamProducers)
            {
                Console.WriteLine("The producer with the most creams is: {0}, with {1} creams", producer.Key, producer.Value);
            }
        }
    }
}
