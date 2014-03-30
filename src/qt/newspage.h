#ifndef NEWSPAGE_H
#define NEWSPAGE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QTimer>

namespace Ui {
    class NewsPage;
}
class ClientModel;
class WalletModel;
class NewsViewDelegate;
class TransactionFilterProxy;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** News ("home") page widget */
class NewsPage : public QWidget
{
    Q_OBJECT

public:
    explicit NewsPage(QWidget *parent = 0);
    ~NewsPage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);

public slots:

signals:

private:
    Ui::NewsPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    NewsViewDelegate *newsdelegate;
    QNetworkAccessManager *nam;

private slots:
    void finished(QNetworkReply *reply);
    void DoHttpGet();
};

#endif // NEWSPAGE_H
