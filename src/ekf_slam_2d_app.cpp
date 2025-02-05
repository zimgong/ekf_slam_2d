
#include "ekf_slam_2d/ekf_slam_2d_wrapper.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ekf_slam_2d");
  ros::NodeHandle n;
  ros::Rate r(100);
  EKFslamWrapper slam;
  slam.get_param();
  slam.init();
  ros::Duration(3).sleep();

  if (!slam.rawlogPlay())
  {  // if not play from rawlog file

    while (ros::ok())
    {
      ros::spinOnce();
      r.sleep();
    }
  }
}
