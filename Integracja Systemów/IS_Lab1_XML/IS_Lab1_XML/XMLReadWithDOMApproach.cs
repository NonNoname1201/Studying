using System.Xml;

internal class XMLReadWithDOMApproach
{
    public static void Read(string filepath)
    {
        // odczyt zawartości dokumentu
        XmlDocument doc = new XmlDocument();
        doc.Load(filepath);
        string postac;
        string sc;
        int count = 0;
        var drugs = doc.GetElementsByTagName("produktLeczniczy");
        foreach (XmlNode d in drugs)
        {
            postac = d.Attributes.GetNamedItem("postac").Value;
            sc = d.Attributes.GetNamedItem("nazwaPowszechnieStosowana").Value;
            if (postac == "Krem" && sc == "Mometasoni furoas")
                count++;
        }
        Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas {0}", count);
    }

    public static void ReadAlt(string filepath)
    {
        XmlDocument doc = new XmlDocument(); 
        doc.Load(filepath);

        Dictionary<string, HashSet<string>> drugsDict = new Dictionary<string, HashSet<string>>();

        var drugs = doc.GetElementsByTagName("produktLeczniczy");
        foreach (XmlNode d in drugs)
        {
            string form = d.Attributes.GetNamedItem("postac").Value;
            string name = d.Attributes.GetNamedItem("nazwaPowszechnieStosowana").Value;

            if (!drugsDict.ContainsKey(name))
            {
                drugsDict[name] = new HashSet<string>();
            }

            drugsDict[name].Add(form);
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
        XmlDocument document = new XmlDocument();
        document.Load(filepath);
        Dictionary<string, int> creamProducers = new Dictionary<string, int>();
        Dictionary<string, int> tabletProducers = new Dictionary<string, int>();

        var drugs = document.GetElementsByTagName("produktLeczniczy");
        foreach (XmlNode d in drugs)
        {
            string producer = d.Attributes.GetNamedItem("podmiotOdpowiedzialny").Value;
            string form = d.Attributes.GetNamedItem("postac").Value;

            if (form == "Krem") // replace "Krem" with the correct value for creams
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
            else if (form == "Tabletka") // replace "Tabletka" with the correct value for tablets
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

        string mostCreams = creamProducers.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
        int maxCreams = creamProducers.Aggregate((l, r) => l.Value > r.Value ? l : r).Value;
        string mostTablets = tabletProducers.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
        int maxTablets = tabletProducers.Aggregate((l, r) => l.Value > r.Value ? l : r).Value;

        Console.WriteLine("The producer with the most creams is: {0}, with {1} creams", mostCreams, maxCreams);
        Console.WriteLine("The producer with the most tablets is: {0}, with {1} tablets", mostTablets, maxTablets);
    }

    public static void ReadTop3CreamProducers(string filepath)
    {
        XmlDocument document = new XmlDocument();
        document.Load(filepath);
        Dictionary<string, int> creamProducers = new Dictionary<string, int>();

        var drugs = document.GetElementsByTagName("produktLeczniczy");
        foreach (XmlNode d in drugs)
        {
            string producer = d.Attributes.GetNamedItem("podmiotOdpowiedzialny").Value;
            string form = d.Attributes.GetNamedItem("postac").Value;

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

        var top3 = creamProducers.OrderByDescending(pair => pair.Value).Take(3);
        foreach (var pair in top3)
        {
            Console.WriteLine("The producer: {0}, with {1} creams", pair.Key, pair.Value);
        }
    }

}
