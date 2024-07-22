#include "stats.h"
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <limits>
#include <cmath>

namespace Statistics
{
	Stats ComputeStatistics(const std::vector<float>& sensorReadings) 
	{
		Stats computedStats;

		if (sensorReadings.empty())
		{
			computedStats.average = std::numeric_limits<float>::quiet_NaN();
			computedStats.min = std::numeric_limits<float>::quiet_NaN();
			computedStats.max = std::numeric_limits<float>::quiet_NaN();
		}
		else
		{
			computedStats.min = *std::min_element(sensorReadings.begin(), sensorReadings.end());
			computedStats.max = *std::max_element(sensorReadings.begin(), sensorReadings.end());
			computedStats.average = std::accumulate(sensorReadings.begin(), sensorReadings.end(), 0.0f) / sensorReadings.size();
		}
		
		return computedStats;
	}
}
