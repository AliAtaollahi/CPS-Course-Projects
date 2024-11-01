#ifndef EMPLOYEESDATABASE_H
#define EMPLOYEESDATABASE_H

#include <QObject>
#include <QVector>
#include "employee.h"

class EmployeesDatabase : public QObject
{
    Q_OBJECT
public:
    explicit EmployeesDatabase(const QString &initialDataPath, QObject *parent = nullptr);

    const QVector<Employee>& getEmployeesVector() const;
    bool checkRFIDMatch(const QString &rfid);

private:
    QVector<Employee> employeesVector_;

    void loadEmployeesFromJson(const QString &path);
    void parseEmployeesJson(const QByteArray &jsonData);
    QByteArray readJsonFile(const QString &path);
};

#endif // EMPLOYEESDATABASE_H
