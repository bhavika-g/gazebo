/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef __GAZEBO_MAGNETOMETER_SENSOR_HH_
#define __GAZEBO_MAGNETOMETER_SENSOR_HH_

#include <string>

#include <sdf/sdf.hh>

#include "gazebo/sensors/Sensor.hh"
#include "gazebo/common/CommonTypes.hh"
#include "gazebo/physics/PhysicsTypes.hh"
#include "gazebo/sensors/SensorTypes.hh"
#include "gazebo/transport/TransportTypes.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace sensors
  {
    /// \addtogroup gazebo_sensors
    /// \{

    /// \class MagnetometerSensor MagnetometerSensor.hh sensors/sensors.hh
    /// \brief MagnetometerSensor to provide magnetic field measurement.
    class GAZEBO_VISIBLE MagnetometerSensor: public Sensor
    {
      /// \brief Constructor.
      public: MagnetometerSensor();

      /// \brief Destructor.
      public: virtual ~MagnetometerSensor();

      // Documentation inherited
      public: virtual void Load(const std::string & _worldName,
                                sdf::ElementPtr _sdf);

      // Documentation inherited
      public: virtual void Load(const std::string & _worldName);

      // Documentation inherited
      public: virtual void Init();

      // Documentation inherited
      protected: virtual bool UpdateImpl(bool _force);

      // Documentation inherited
      public: virtual void Fini();

      /// \brief Accessor for current magnetic field in Tesla
      /// \return Current magnetic field
      public: math::Vector3 GetMagneticField() const;

      /// \brief Mutex to protect reads and writes.
      private: mutable boost::mutex mutex;
      
      /// \brief Magnetometer data publisher.
      private: transport::PublisherPtr magPub;

      /// \brief Topic name for magnetometer data publisher.
      private: std::string topicName;

      /// \brief Parent link of this sensor.
      private: physics::LinkPtr parentLink;

      /// \brief Stores most recent magnetometer sensor data.
      private: msgs::Magnetometer magMsg;
    };
    /// \}
  }
}
#endif