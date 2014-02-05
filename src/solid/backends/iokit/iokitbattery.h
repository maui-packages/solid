/*
    Copyright 2009 Harald Fernengel <harry@kdevelop.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SOLID_BACKENDS_IOKIT_BATTERY_H
#define SOLID_BACKENDS_IOKIT_BATTERY_H

#include <solid/ifaces/battery.h>
#include "iokitdeviceinterface.h"

namespace Solid
{
namespace Backends
{
namespace IOKit
{
class IOKitDevice;

class Battery : public DeviceInterface, virtual public Solid::Ifaces::Battery
{
    Q_OBJECT
    Q_INTERFACES(Solid::Ifaces::Battery)

public:
    Battery(IOKitDevice *device);
    virtual ~Battery();

    bool isPlugged() const;
    Solid::Battery::BatteryType type() const;

    int chargePercent() const;
    int capacity() const;

    bool isRechargeable() const;
    bool isPowerSupply() const;

    Solid::Battery::ChargeState chargeState() const;

    // ### the ones below are TODO
    Solid::Battery::Technology technology() const { return Solid::Battery::UnknownTechnology; }
    double energy() const { return 0.0; }
    double energyRate() const { return 0.0; }
    double voltage() const { return 0.0; }

Q_SIGNALS:
    void energyChanged(double energy, const QString &udi);
    void energyRateChanged(double energyRate, const QString &udi);
    void chargePercentChanged(int value, const QString &udi);
    void capacityChanged(int value, const QString &udi);
    void chargeStateChanged(int newState, const QString &udi);
    void plugStateChanged(bool newState, const QString &udi);
    void powerSupplyStateChanged(bool newState, const QString &udi);
};
}
}
}

#endif // SOLID_BACKENDS_IOKIT_BATTERY_H
