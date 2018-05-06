-- phpMyAdmin SQL Dump
-- version 4.7.6
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Feb 04, 2018 at 11:02 AM
-- Server version: 10.1.29-MariaDB
-- PHP Version: 7.0.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `id3789153_findmybus`
--

-- --------------------------------------------------------

--
-- Table structure for table `balangoda`
--

CREATE TABLE `balangoda` (
  `id` int(11) NOT NULL,
  `busid` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `chtime` time DEFAULT NULL,
  `checked` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `beragala`
--

CREATE TABLE `beragala` (
  `id` int(11) NOT NULL,
  `busid` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `chtime` time DEFAULT NULL,
  `checked` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `beragala`
--

INSERT INTO `beragala` (`id`, `busid`, `chtime`, `checked`) VALUES
(65, 'CA-7625', '05:56:50', 1);

-- --------------------------------------------------------

--
-- Table structure for table `busdetails`
--

CREATE TABLE `busdetails` (
  `id` int(11) NOT NULL,
  `busid` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `destination` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  `routeno` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `pambahinna`
--

CREATE TABLE `pambahinna` (
  `id` int(11) NOT NULL,
  `busid` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `chtime` time DEFAULT NULL,
  `checked` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `balangoda`
--
ALTER TABLE `balangoda`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `beragala`
--
ALTER TABLE `beragala`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `busdetails`
--
ALTER TABLE `busdetails`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `pambahinna`
--
ALTER TABLE `pambahinna`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `balangoda`
--
ALTER TABLE `balangoda`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=76;

--
-- AUTO_INCREMENT for table `beragala`
--
ALTER TABLE `beragala`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=66;

--
-- AUTO_INCREMENT for table `busdetails`
--
ALTER TABLE `busdetails`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `pambahinna`
--
ALTER TABLE `pambahinna`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
