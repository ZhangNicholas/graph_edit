#pragma once

#include <list>
#include <memory>

/**
 * \Observer interface
 * @brief Observers are notified about Observable objects updates they subscribed to.
 */
class IObserver
{
public:
	virtual void update() const noexcept = 0;

	virtual ~IObserver() = default;
};

/**
 * \Observable interface
 * @brief Observables notify subscribed Observers about changes.
 */
class  IObservable
{
public:

	IObservable() = default;
	virtual ~IObservable() = default;

	void subscribe(std::shared_ptr<IObserver> observer_) noexcept
	{
		_observers.push_back(observer_);
	}

	void unsubscribe(std::shared_ptr<IObserver> observer_) noexcept
	{
		_observers.remove_if([observer_](std::weak_ptr<IObserver>& w_ptr) {
			return w_ptr.expired() || w_ptr.lock() == observer_;
			});
	}

	void notify() noexcept
	{
		for (auto& w_ptr : _observers)
		{
			if (!w_ptr.expired())
			{
				w_ptr.lock()->update();
			}
		}
	}

private:
	std::list<std::weak_ptr<IObserver>> _observers;
};