using IS_Lab1_XML;

internal class Program
{
    private static void Main(string[] args)
    {
        string xmlpath = Path.Combine("Assets", "data.xml");


        // odczyt danych z wykorzystaniem DOM
        Console.WriteLine("XML loaded by DOM Approach");

        XMLReadWithDOMApproach.Read(xmlpath);
        XMLReadWithDOMApproach.ReadAlt(xmlpath);
        XMLReadWithDOMApproach.ReadWhoMore(xmlpath);
        XMLReadWithDOMApproach.ReadTop3CreamProducers(xmlpath);

        // odczyt danych z wykorzystaniem SAX
        Console.WriteLine("XML loaded by SAX Approach");

        XMLReadWithSSAXApproach.Read(xmlpath);
        XMLReadWithSSAXApproach.ReadAlt(xmlpath);
        XMLReadWithSSAXApproach.ReadWhoMore(xmlpath);
        XMLReadWithSSAXApproach.ReadTop3CreamProducers(xmlpath);


        // odczyt danych z wykorzystaniem XPath i DOM
        Console.WriteLine("XML loaded with XPath");

        XMLReadWithXLSTDOM.Read(xmlpath);
        XMLReadWithXLSTDOM.ReadAlt(xmlpath);
        XMLReadWithXLSTDOM.ReadTop3CreamProducers(xmlpath);

        

        // odczyt danych z głębszą analizą
        Console.WriteLine("XML loaded with Deep Analysis");
        
        XMLDeepReadAnalysis.Read(xmlpath);

        Console.ReadLine();
        //pause console

    }
}
