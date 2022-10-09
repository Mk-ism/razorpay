package com.infosys.service;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.infosys.model.SimDetails;
import com.infosys.model.SimOffers;
import com.infosys.repository.SimDetailsRepo;
import com.infosys.repository.SimOffersRepo;


@Service
public class SimServiceImpl implements SimService {

	@Autowired
	SimOffersRepo  repo;
	
	@Autowired
	SimDetailsRepo repo1;
	
	@Override
	public SimOffers simoffersdetail(SimOffers obj) {
		// TODO Auto-generated method stub
		
		return repo.save(obj);
	}
	
	@Override
	public SimDetails savedetails(SimDetails ob) {
		return repo1.save(ob);
	}

	@Override
	public SimDetails ShowSimDetils(long serviceNumber, long simNumber) {
		
		List<SimDetails> list=new ArrayList<>();
		list=repo1.findAll();
		int i=0;
		while(i<list.size())
		{
			if(list.get(i).getServiceNumber()==serviceNumber && list.get(i).getSimNumber()==simNumber)
			{
				return list.get(i);
			}
			i++;
		}
		return null;
	}

	@Override
	public String ShowOffers(long sim_Id) {
		
		
       List<SimOffers> simofferslist=repo.findAll();
		
		int i=0;
		while(i<simofferslist.size())
		{
			if(simofferslist.get(i).getSimId()==sim_Id)
			{
				return simofferslist.get(i).getOfferName();
			}
			i++;
		} 
		/*
		int i=(int)sim_Id; 
		java.util.Optional<SimOffers> dbCustomer = repo.findBysimId(i);
		if(dbCustomer.isPresent()) {
		    SimOffers existingCustomer = dbCustomer.get();
		    String nameWeWanted = existingCustomer.getOfferName();
		    //operate on existingCustomer
		} else {
			throw new com.infosys.exception.ResourceNotFoundException("SimOffers","sim_Id","simId");
		    //there is no Customer in the repo with 'id'
		}
		*/
		
		return "else";
		
		
	}
	
	
}
