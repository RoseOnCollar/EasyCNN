#pragma once
#include "EasyCNN/Configure.h"
#include "EasyCNN/Layer.h"

namespace EasyCNN
{
	class PoolingLayer : public Layer
	{
	public:
		enum class PoolingType
		{
			MaxPooling,
			MeanPooling
		};
	public:
		PoolingLayer();
		virtual ~PoolingLayer();
	public:
		void setParamaters(const PoolingType _poolingType,const BucketSize _poolingKernelSize);
	public:
		DECLARE_LAYER_TYPE;
		virtual std::string getLayerType() const;
		virtual void solveInnerParams();
		virtual void forward(const std::shared_ptr<DataBucket> prevDataBucket, std::shared_ptr<DataBucket> nextDataBucket);
		virtual void backward(std::shared_ptr<DataBucket> prevDataBucket, const std::shared_ptr<DataBucket> nextDataBucket);
	private:
		PoolingType poolingType = PoolingType::MaxPooling;
		BucketSize poolingKernelSize;
	};
}