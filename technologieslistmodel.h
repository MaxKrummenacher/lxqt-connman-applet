#ifndef TECHNOLOGIESLISTMODEL_H
#define TECHNOLOGIESLISTMODEL_H

#include <QAbstractListModel>
#include <QDBusInterface>
#include <QVariantMap>
#include "dbus_types.h"

struct TechnologiesListModelPrivate;

/**
 * @brief The TechnologiesListModel class wraps a list of tecnologies
 */
class TechnologiesListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit TechnologiesListModel(QObject *parent = 0);
    virtual ~TechnologiesListModel();
    virtual int rowCount(const QModelIndex& parent) const;
    virtual QVariant data(const QModelIndex& index, int role) const;

public slots:
    void onTechnologyAdded(const QDBusObjectPath& path, const QVariantMap& properties);
    void onTechnologyRemoved(const QDBusObjectPath& path);
    void onTechnologyUpdated(const QString& name, const QDBusVariant& newValue);

private:
    TechnologiesListModelPrivate* modelData;
};

#endif // TECHNOLOGIESLISTMODEL_H
