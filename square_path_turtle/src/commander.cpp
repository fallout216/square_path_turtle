#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char** argv){
  const double spd = 0.5;

  ros::init(argc, argv, "commander");
  ros::NodeHandle nh;
  ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);
  
  ros::Rate loop_rate(1);
  int count = 0;
  
  while(ros::ok()){

	  geometry_msgs::Twist cmd_Twist;
          cmd_Twist.linear.x = spd;
	  
          if (count % 2 == 0){
	    cmd_Twist.angular.z = 0;
	  }else if(count % 2 == 1){
	    cmd_Twist.angular.z = 1.57;
	  }
	 
	  chatter_pub.publish(cmd_Twist);

	  ros::spinOnce();
	  loop_rate.sleep();

	  count++;
  }
  return 0;
} 
