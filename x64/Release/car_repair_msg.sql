/*
Navicat MySQL Data Transfer

Source Server         : MySQL
Source Server Version : 50721
Source Host           : localhost:3306
Source Database       : car_repair_msg

Target Server Type    : MYSQL
Target Server Version : 50721
File Encoding         : 65001

Date: 2020-05-21 15:03:41
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for server_form
-- ----------------------------
DROP TABLE IF EXISTS `server_form`;
CREATE TABLE `server_form` (
  `id` int(11) NOT NULL,
  `car_num` varchar(255) NOT NULL,
  `contact` varchar(255) DEFAULT NULL,
  `contact_way` varchar(255) DEFAULT NULL,
  `serve_list` varchar(255) DEFAULT NULL,
  `other` varchar(255) DEFAULT NULL,
  `cost` double(10,2) DEFAULT NULL,
  `time` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of server_form
-- ----------------------------
INSERT INTO `server_form` VALUES ('1', '湘AD2K12', '刘', '2222', '123', '已处理', '100.00', '2020-5-20 17:27:16');
INSERT INTO `server_form` VALUES ('2', '123', 'A', '232', '2323', '未处理', '11.50', '2020-5-20 17:27:5');

-- ----------------------------
-- Table structure for user_form
-- ----------------------------
DROP TABLE IF EXISTS `user_form`;
CREATE TABLE `user_form` (
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of user_form
-- ----------------------------
INSERT INTO `user_form` VALUES ('admin', '123');
