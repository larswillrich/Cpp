/*
 * Liste.h
 *
 *  Created on: 09.01.2013
 *      Author: Lars Willrich
 */

#ifndef liste_h
#define liste_h liste_h
#include <cstddef>     // f�r NULL
#include <cassert>     // f�r assert

template<class T> class Liste
{
   private:
      struct Listenelement
      {
         T Daten;
         Listenelement *Next, *Prev;
         // Konstruktur:
         Listenelement(): Next(NULL), Prev(NULL)
         { }
      };

      Listenelement *Ende, *Anfang;
      int Anzahl;

   public:
      Liste();                // Konstruktor
      Liste(const Liste&);    // Kopierkonstruktor
      virtual ~Liste();       // Destruktor

      Liste& operator=(const Liste&);
      T operator[](int id);

      bool empty() const { return Anzahl == 0; }
      int size()   const { return Anzahl; }

      // am Anfang bzw. Ende einf�gen
      void push_front(const T&);
      void push_back(const T&);

      // am Anfang bzw. Ende entnehmen
      void pop_front();
      void pop_back();

      // am Anfang bzw. Ende lesen
      T& front();
      const T& front() const;
      T& back();
      const T& back() const;

      // ========================================
      // Jetzt kommt die geschachtelte
      // Klasse f�r den Iterator:
      class Iterator
      {
         private:
            Listenelement* aktuell; // Zeiger auf
                             // aktuelles Element
         public:
            friend Liste;    // wg. erase-Zugriff
                             // auf aktuell
            Iterator(Listenelement* Init = NULL)
            : aktuell(Init)
            { }

            Iterator(const Liste& L)
            {  *this = L.begin(); }

            //Dereferenzierung:
            const T& operator*() const
            {  return aktuell->Daten; }

            T& operator*()
            {  return aktuell->Daten; }

            Iterator& operator++() // prefix
            {
               if (aktuell)
                  aktuell = aktuell->Next;
               return *this;
            }

            Iterator operator++(int) // postfix
            {
               Iterator temp = *this;
               ++*this;
               return temp;
            }

            bool operator==(const Iterator& x) const
            {  return aktuell == x.aktuell; }

            bool operator!=(const Iterator& x) const
            {  return aktuell != x.aktuell; }

      }; // Iterator
      // Hier ist Deklaration und Definition
      // des Iterators zu Ende!
      // ========================================

      // Methoden der Klasse Liste,
      // die die Klasse Iterator benutzen:

      Iterator begin() const
      {  return Iterator(Anfang); }

      Iterator end() const
      {  return Iterator(); } // NULL-Iterator

      void erase(Iterator& pos) // Element l�schen
      {
         if (pos.aktuell == Anfang)
         {
            pop_front();
            pos.aktuell = Anfang; // neuer Anfang
         }
         else
            if (pos.aktuell == Ende)
            {
               pop_back();
               pos.aktuell = Ende;
            }
            else
            {
               // zwischen 2 Elementen ausketten
               pos.aktuell->Next->Prev =
                            pos.aktuell->Prev;
               pos.aktuell->Prev->Next =
                            pos.aktuell->Next;
               Listenelement *temp = pos.aktuell;
               pos.aktuell = pos.aktuell->Next;
               delete temp;
               Anzahl--;
            }
      }

      // Vor pos einf�gen
      Iterator insert(Iterator pos, const T& Wert)
      {
         if (pos == begin())
         {
            push_front(Wert);
            return Iterator(Anfang);
         }
         if (pos == end())
         {
            push_back(Wert);
            return Iterator(Ende);
         }
         // zwischen 2 Elementen einketten
         Listenelement *temp = new Listenelement;
         temp->Daten = Wert;
         temp->Next = pos.aktuell;
         temp->Prev = pos.aktuell->Prev;
         pos.aktuell->Prev->Next=temp;
         pos.aktuell->Prev = temp;
         Anzahl++;
         return Iterator(temp);
      }
};

// ===== Implementierung der Klasse Liste =====
// soweit nicht schon geschehen

template<class T>           // Konstruktor
inline Liste<T>::Liste()
:Ende(NULL), Anfang(NULL), Anzahl(0)
{ }

template<class T>           // Kopierkonstruktor
inline Liste<T>::Liste(const Liste<T>& L)
:Ende(NULL), Anfang(NULL), Anzahl(0)
{
   Listenelement *temp = L.Ende;
   while(temp)
   {
      push_front(temp->Daten);
      temp = temp->Prev;
   }
}

template<class T>           // Destruktor
inline Liste<T>::~Liste()
{
   while(!empty())
      pop_front();
}

template<class T>           // Zuweisungsoperator
inline Liste<T>& Liste<T>::operator=(const Liste<T>& L)
{
   if (this != &L) // Selbstzuweisung ausschlie�en
   {
      while(!empty())
         pop_front(); // alles l�schen
      // ... und neu aufbauen
      Listenelement *temp = L.Ende;
      while(temp)
      {
         push_front(temp->Daten);
         temp = temp->Prev;
      }
   }
   return *this;
}

template<class T>
inline T Liste<T>::operator[](int id){

	if (id >= this->size()) return NULL;
	Liste::Iterator it(Anfang);
	if (Anfang == Ende) return Anfang->Daten;
	int i = 0;
	do{
		if (i == id) return it.aktuell->Daten;
		i++;
	}while(it++ != Ende);

	/*for (int i = 0;it != Ende;it++){
		if (i == id) return it.aktuell->Daten;
		i++;
	}*/
	return NULL;
}

template<class T>
inline void Liste<T>::push_front(const T& Dat)
{
   Listenelement *temp = new Listenelement;
   temp->Daten = Dat;
   temp->Prev = NULL;
   temp->Next = Anfang;
   if (!Anfang)
      Ende=temp; // einziges Element
   else
      Anfang->Prev = temp;
   Anfang = temp;
   Anzahl++;
}

template<class T>
inline void Liste<T>::push_back(const T& Dat)
{
   Listenelement *temp = new Listenelement;
   temp->Daten = Dat;
   temp->Prev = Ende;
   temp->Next = NULL;
   if (!Ende)
      Anfang=temp; // einziges Element
   else
      temp->Prev->Next = temp;
   Ende = temp;
   Anzahl++;
}

template<class T>
inline void Liste<T>::pop_front()
{
   assert(!empty());
   Listenelement *temp = Anfang;
   Anfang = temp->Next;
   if (!Anfang)
      // d.h. kein weiteres Element vorhanden
      Ende = NULL;
   else
      Anfang->Prev = NULL;
   delete temp;
   Anzahl--;
}

template<class T>
inline void Liste<T>::pop_back()
{
   assert(!empty());
   Listenelement *temp = Ende;
   Ende = temp->Prev;
   if (!Ende)
      // d.h. kein weiteres Element vorhanden
      Anfang = NULL;
   else
      Ende->Next = NULL;
   delete temp;
   Anzahl--;
}

template<class T>
inline T& Liste<T>::front()
{
   assert(!empty());
   return Anfang->Daten;
}

template<class T>
inline const T& Liste<T>::front() const
{
   assert(!empty());
   return Anfang->Daten;
}

template<class T>
inline T& Liste<T>::back()
{
   assert(!empty());
   return Ende->Daten;
}

template<class T>
inline const T& Liste<T>::back() const
{
   assert(!empty());
   return Ende->Daten;
}

#endif
