#ifndef MSTREAM_HPP
#define MSTREAM_HPP
#include <fstream>
#include <iostream>

/* Classe mstream permet l'affichage sur la console et sur un fichier*/
class mstream
{
	public:
		static mstream mout;

		std::ofstream coss;

		/* Constructeur : mstream
		*/
		mstream(void);

		/* Destructeur : ~mstream
		 * Permet de détruire l'objet
		 */
		~mstream(void);

		/* Redefinition operateur <<*/
		template <class T>
			friend mstream& operator<< (mstream& st, T val);

mstream& operator<< (std::ostream& (*pfun)(std::ostream&))
{
	pfun(coss);
	pfun(std::cout);
	return *this;
}

};

	template <class T>
mstream& operator<< (mstream& st, const T val)
{
	st.coss << val;
	std::cout << val;
	return st;
}

#endif // MSTREAM_HPP
