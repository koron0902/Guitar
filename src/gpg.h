#ifndef GPG_H
#define GPG_H

#include <QDateTime>
#include <QString>


class gpg {
public:
	struct Data {
//		unsigned int len = 0;
//		char type = 0;
		QString id;
		unsigned int year = 0;
		unsigned int month = 0;
		unsigned int day = 0;
		QString name;
		QString comment;
		QString mail;
		QByteArray fingerprint;
	};

	static bool listKeys(const QString &gpg_command, QList<gpg::Data> *keys);






public:
	struct Key {
		QString id;
		QDateTime timestamp;
	};

	struct UID {
		QString name;
		QString email;
		QString comment;
	};

	struct Item {
		Key pub;
		QList<Key> sub;
		QList<UID> uid;
	};

	static QList<Item> load(QByteArray const &json);

};

#endif // GPG_H
